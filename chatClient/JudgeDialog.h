#ifndef JUDGEDIALOG_H
#define JUDGEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QWidget>

class JudgeDialog : public QDialog {
Q_OBJECT
public:
    JudgeDialog(QWidget *p=NULL);
signals:
    void sendResult(bool);
private:
    bool result;
    QPushButton *btnok;
    QPushButton *btncancel;
public slots:
    void judgeOk();
    void judgeCancel();
};

#endif // JUDGEDIALOG_H
