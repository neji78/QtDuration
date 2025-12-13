/**
 * @file QDuration_global.h
 * @brief Global definitions and macros for the QDuration library.
 *
 * This header contains:
 * - Export/import macros for shared library usage
 * - Common Qt includes required by the library
 * - Time-related constants expressed in seconds
 * - Namespace helper macros for QtDuration
 *
 * This file is included by public headers and should remain lightweight
 * and stable as part of the public API.
 */

#ifndef QDURATION_GLOBAL_H
#define QDURATION_GLOBAL_H
#pragma once

#include <QtCore/qglobal.h>
#include <QTime>
#include <QString>
#include <QDebug>

/**
 * @def QDURATION_EXPORT
 * @brief Export/import macro for the QDuration shared library.
 *
 * When building the QDuration library, QDURATION_LIBRARY should be defined
 * and symbols will be exported. When using the library, symbols will be
 * imported.
 */
#if defined(QDURATION_LIBRARY)
#  define QDURATION_EXPORT Q_DECL_EXPORT
#else
#  define QDURATION_EXPORT Q_DECL_IMPORT
#endif

/** @name Time constants (in seconds) */
///@{

/** @brief Number of seconds in one year (365 days). */
#define YEAR_SECONDS   31536000

/** @brief Number of seconds in one month (30 days). */
#define MONTH_SECONDS  2592000

/** @brief Number of seconds in one day. */
#define DAY_SECONDS    86400

/** @brief Number of seconds in one hour. */
#define HOUR_SECONDS   3600

/** @brief Number of seconds in one minute. */
#define MINUTE_SECONDS 60

///@}

/**
 * @def Q_DURATION_BEGIN_NAMESPACE
 * @brief Opens the QtDuration namespace.
 */
#define Q_DURATION_BEGIN_NAMESPACE namespace QtDuration {

/**
 * @def Q_DURATION_END_NAMESPACE
 * @brief Closes the QtDuration namespace.
 */
#define Q_DURATION_END_NAMESPACE }

#endif // QDURATION_GLOBAL_H
