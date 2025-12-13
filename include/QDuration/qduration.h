/**
 * @file QDuration.h
 * @brief Declaration of the QDuration class.
 *
 * QDuration provides a convenient way to represent and manipulate a duration
 * consisting of a time component (hours, minutes, seconds, milliseconds)
 * together with date-based components (days, months, years).
 *
 * @note This class is designed to work with Qt types such as QTime, QString,
 * and QDebug.
 */

#ifndef QDURATION_H
#define QDURATION_H

#include "qduration_global.h"

Q_DURATION_BEGIN_NAMESPACE

    class QDuration;

/**
 * @brief Stream operator for debugging.
 *
 * Allows a QDuration object to be printed using QDebug.
 *
 * @param dbg The QDebug stream.
 * @param duration The duration to be printed.
 * @return The updated QDebug stream.
 */
QDURATION_EXPORT QDebug operator<<(QDebug dbg, const QDuration &duration);

/**
 * @class QDuration
 * @brief Represents a date-time duration.
 *
 * QDuration encapsulates a duration composed of:
 * - A QTime component (hours, minutes, seconds, milliseconds)
 * - Date-based offsets (days, months, years)
 *
 * It supports arithmetic operations (adding time units), string conversion,
 * validation, and conversion to total seconds or milliseconds.
 */
class QDURATION_EXPORT QDuration
{
public:
    /**
     * @brief Constructs an empty (zero) duration.
     *
     * All components (time, days, months, years) are initialized to zero.
     */
    explicit QDuration();

    /**
     * @brief Constructs a duration from a QTime and optional date components.
     *
     * @param time   Time component of the duration.
     * @param days   Number of days (default: 0).
     * @param months Number of months (default: 0).
     * @param years  Number of years (default: 0).
     */
    explicit QDuration(QTime time, int days = 0, int months = 0, int years = 0);

    /**
     * @brief Assignment operator.
     * @param obj Another QDuration instance.
     * @return Reference to this object.
     */
    QDuration &operator =(const QDuration &obj);

    /**
     * @brief Converts the duration to a human-readable string.
     *
     * @return String representation of the duration.
     */
    QString toString() const;

    /**
     * @brief Creates a QDuration from separate time and date duration strings.
     *
     * @param timeDurationString Time part (e.g. "01:30:00").
     * @param dateDurationString Date part (e.g. "2d 1m 1y").
     * @return Parsed QDuration instance.
     */
    static QDuration fromString(const QString &timeDurationString,
                                const QString &dateDurationString);

    /**
     * @brief Creates a QDuration from a single duration string.
     *
     * @param durationString Combined duration string.
     * @return Parsed QDuration instance.
     */
    static QDuration fromString(const QString &durationString);

    /** @name Additive modifiers */
    ///@{

    /** @brief Adds milliseconds to the duration. */
    void addMilliseconds(int milliseconds);

    /** @brief Adds seconds to the duration. */
    void addSeconds(int seconds);

    /** @brief Adds minutes to the duration. */
    void addMinutes(int minutes);

    /** @brief Adds hours to the duration. */
    void addHours(int hours);

    /** @brief Adds days to the duration. */
    void addDays(int days);

    /** @brief Adds months to the duration. */
    void addMonths(int months);

    /** @brief Adds years to the duration. */
    void addYears(int years);

    ///@}

    /**
     * @brief Resets the duration to zero.
     */
    void clearDuration();

    /**
     * @brief Returns a copy of this duration.
     * @return A new QDuration instance with the same values.
     */
    QDuration toDuration() const;

    /** @name Getters */
    ///@{

    /**
     * @brief Returns the seconds component of the time.
     */
    int seconds() const;

    /**
     * @brief Returns the time component.
     */
    QTime getTime() const;

    /**
     * @brief Checks whether the duration is valid.
     *
     * @return true if valid, false otherwise.
     */
    bool isValid() const;

    /** @brief Returns the hour component of the time. */
    int hours() const;

    /** @brief Returns the minute component of the time. */
    int minutes() const;

    /** @brief Returns the number of days. */
    int days() const { return days_; }

    /** @brief Returns the number of months. */
    int months() const { return months_; }

    /** @brief Returns the number of years. */
    int years() const { return years_; }

    ///@}

    /**
     * @brief Converts the duration to seconds using a base time.
     * @param time Base QTime.
     * @return Total seconds.
     */
    int toTimeSeconds(QTime time) const;

    /**
     * @brief Converts the duration to milliseconds using a base time.
     * @param time Base QTime.
     * @return Total milliseconds.
     */
    int toTimeMilliseconds(QTime time) const;

    /**
     * @brief Converts the duration to total seconds.
     */
    int toSeconds() const;

    /**
     * @brief Converts the duration to total milliseconds.
     */
    int toMilliseconds() const;

    /**
     * @brief Converts the duration's time component to seconds.
     */
    int toTimeSeconds() const;

    /**
     * @brief Converts the duration's time component to milliseconds.
     */
    int toTimeMilliseconds() const;

private:
    int days_;    /**< Number of days in the duration */
    int months_;  /**< Number of months in the duration */
    int years_;   /**< Number of years in the duration */
    QTime time_;  /**< Time component of the duration */
};

Q_DURATION_END_NAMESPACE

#endif // QDURATION_H
