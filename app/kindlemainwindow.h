#ifndef KINDLEMAINWINDOW_H
#define KINDLEMAINWINDOW_H

#include <QWebView>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QWSServer>
#include <QDebug>
#include <QListWidget>
#include <QEvent>
#include <QMouseEvent>

#include "ui_kindlemainwindow.h"

#include <article_maker.hh>
#include <article_netmgr.hh>
#include <articleview.hh>
#include "dictionarybar.hh"
#include "wordfinder.hh"
#include "loaddictionaries.hh"

class KindleMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit KindleMainWindow( Config::Class & cfg );
    ~KindleMainWindow();

private slots:
    void translateInputChanged( QString const & );
    void translateInputFinished(  );
    void showTranslationFor( QString const & word, unsigned group = 0 );
    void on_actionSelect_triggered();
    void on_actionClose_triggered();
    void typingEvent( QString const & );

    /// Gives the keyboard focus to the translateLine and selects all the text it has.
    void focusTranslateLine();

    void prefixMatchUpdated();
    void prefixMatchFinished();

private:
    Ui::MainWindow *ui;
    Config::Class & cfg;
    Config::Events configEvents;
    ArticleView * articleView;
    QListWidget * wordList;

    ArticleView * getCurrentArticleView();

    DictionaryBar dictionaryBar;

    ArticleMaker articleMaker;
    ArticleNetworkAccessManager articleNetMgr;
    QNetworkAccessManager dictNetMgr; // We give dictionaries a separate manager,
                                      // since their requests can be destroyed
                                      // in a separate thread

    vector< sptr< Dictionary::Class > > dictionaries;
    Instances::Groups groupInstances;

    GroupComboBox * groupList;

    vector< sptr< Dictionary::Class > > dictionariesUnmuted;

    WordFinder wordFinder;

    /// Applies the qt's stylesheet, given the style's name.
    void applyQtStyleSheet( QString const & displayStyle );

    void makeDictionaries();

    void updateMatchResults( bool finished );

    virtual bool eventFilter( QObject *, QEvent * );
};

#endif // KINDLEMAINWINDOW_H
