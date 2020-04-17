// Copyright (c) 2017-2020 The PIVX developers
// Copyright (c) 2020 The YEP developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZYEPCONTROLDIALOG_H
#define ZYEPCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zyep/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZYEPControlDialog;
}

class CZYEPControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZYEPControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZYEPControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZYEPControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZYEPControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZYEPControlDialog(QWidget *parent);
    ~ZYEPControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZYEPControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZYEPControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZYEPCONTROLDIALOG_H
