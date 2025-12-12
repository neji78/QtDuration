#ifndef QDURATION_GLOBAL_H
#define QDURATION_GLOBAL_H
#pragma once

#include <QtCore/qglobal.h>

#if defined(QDURATION_LIBRARY)
#  define QDURATION_EXPORT Q_DECL_EXPORT
#else
#  define QDURATION_EXPORT Q_DECL_IMPORT
#endif

#endif // QDURATION_GLOBAL_H
