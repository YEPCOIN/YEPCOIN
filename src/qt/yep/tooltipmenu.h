// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2020 The YEP developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TOOLTIPMENU_H
#define TOOLTIPMENU_H

#include "qt/yep/pwidget.h"
#include <QWidget>
#include <QModelIndex>

class YEPGUI;
class WalletModel;

namespace Ui {
class TooltipMenu;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

class TooltipMenu : public PWidget
{
    Q_OBJECT

public:
    explicit TooltipMenu(YEPGUI* _window, QWidget *parent = nullptr);
    ~TooltipMenu() override;

    void setIndex(const QModelIndex &index);
    virtual void showEvent(QShowEvent *event) override;

    void setEditBtnText(QString btnText);
    void setDeleteBtnText(QString btnText);
    void setCopyBtnText(QString btnText);
    void setLastBtnText(QString btnText, int minHeight = 30);
    void setCopyBtnVisible(bool visible);
    void setDeleteBtnVisible(bool visible);
    void setEditBtnVisible(bool visible);
    void setLastBtnVisible(bool visible);

signals:
    void onDeleteClicked();
    void onCopyClicked();
    void onEditClicked();
    void onLastClicked();

private slots:
    void deleteClicked();
    void copyClicked();
    void editClicked();
    void lastClicked();

private:
    Ui::TooltipMenu *ui;
    QModelIndex index;
};

#endif // TOOLTIPMENU_H
