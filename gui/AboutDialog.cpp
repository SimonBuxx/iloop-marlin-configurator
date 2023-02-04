#include "AboutDialog.h"
#include "ui_AboutDialog.h"

AboutDialog::AboutDialog(QWidget *pParent) :
    QDialog(pParent),
    mUi(new Ui::AboutDialog)
{
    mUi->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete mUi;
}
