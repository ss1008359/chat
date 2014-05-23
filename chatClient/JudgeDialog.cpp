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
    this->setWindowTitle(tr("私聊请求"));
    this->resize(300, 100);
    this->move((1366-300)/2, (768-100)/2);

    btnok = new QPushButton(tr("接受"), this);
    btncancel = new QPushButton(tr("拒绝"), this);
    btnok->move(50, 50);
    btncancel->move(200, 50);

    connect(btnok, SIGNAL(clicked()), this, SLOT(judgeOk()));
    connect(btncancel, SIGNAL(clicked()), this, SLOT(judgeCancel()));
}
