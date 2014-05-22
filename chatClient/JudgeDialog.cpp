#include "JudgeDialog.h"

void JudgeDialog::judgeOk()
{
    emit sendResult(true);
    accept();
}

void JudgeDialog::judgeCancel()
{
    emit sendResult(false);
    reject();
}

JudgeDialog::JudgeDialog(QWidget *p)
{
    this->resize(100, 100);
    this->move((1366-100)/2, (768-100)/2);

    btnok = new QPushButton(tr("接受"), this);
    btncancel = new QPushButton(tr("拒绝"), this);
    btnok->move(30, 50);
    btncancel->move(60, 50);

    connect(btnok, SIGNAL(clicked()), this, SLOT(judgeOk()));
    connect(btncancel, SIGNAL(clicked()), this, SLOT(judgeCancel()));
}
