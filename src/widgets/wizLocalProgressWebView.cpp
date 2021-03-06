#include "wizLocalProgressWebView.h"
#include <QMovie>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QLabel>
#include <QVBoxLayout>
#include <QPalette>
#include "share/wizwebengineview.h"

CWizLocalProgressWebView::CWizLocalProgressWebView(QWidget *parent) : QWidget(parent)
{
    setContentsMargins(0, 0, 0, 0);

    m_web = new WizWebEngineView(this);
    m_web->settings()->setAttribute(QWebEngineSettings::LocalStorageEnabled, true);
    //
    m_web->setPage(new WizWebEnginePage());

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);

    layout->addWidget(m_web);
}

CWizLocalProgressWebView::~CWizLocalProgressWebView()
{

}
WizWebEngineView* CWizLocalProgressWebView::web()
{
    return m_web;
}


void CWizLocalProgressWebView::hideEvent(QHideEvent* ev)
{
    QWidget::hideEvent(ev);

    emit widgetStatusChanged();
}

void CWizLocalProgressWebView::showEvent(QShowEvent* ev)
{
    emit willShow();

    QWidget::showEvent(ev);

    emit widgetStatusChanged();
}

