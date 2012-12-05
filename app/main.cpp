#include "kindlemainwindow.h"
#include <QApplication>
#include "config.hh"
#include <QDebug>
#include "gdappstyle.hh"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyle(new GdAppStyle);

    Config::Class cfg( Config::load() );
    KindleMainWindow w(cfg);

    if ( Config::isPortableVersion() )
    {
      // For portable version, hardcode some settings

      cfg.paths.clear();
      cfg.paths.push_back( Config::Path( Config::getPortableVersionDictionaryDir(), true ) );
      cfg.soundDirs.clear();
      cfg.hunspell.dictionariesPath = Config::getPortableVersionMorphoDir();
    }

    qDebug() << "Config Dir: " << Config::getConfigDir();

    w.showFullScreen();
    
    return a.exec();
}
