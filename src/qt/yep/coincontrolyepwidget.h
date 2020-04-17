// Copyright (c) 2019 The PIVX developers
// Copyright (c) 2020 The YEP developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLYEPWIDGET_H
#define COINCONTROLYEPWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlYEPWidget;
}

class CoinControlYEPWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlYEPWidget(QWidget *parent = nullptr);
    ~CoinControlYEPWidget();

private:
    Ui::CoinControlYEPWidget *ui;
};

#endif // COINCONTROLYEPWIDGET_H
