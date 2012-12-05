#ifndef LIBGD_GLOBAL_H
#define LIBGD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBGD_LIBRARY)
#  define LIBGDSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBGDSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBGD_GLOBAL_H
