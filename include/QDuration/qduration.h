#ifndef QDURATION_H
#define QDURATION_H

#include "qduration_global.h"
#include <QTime>
#include <QString>
#include <QDebug>

namespace QtDuration {
class QDuration;
QDURATION_EXPORT QDebug operator<<(QDebug dbg, const QDuration &duration);
class QDURATION_EXPORT QDuration
{

public:
    explicit QDuration();
    explicit QDuration(QTime time, int days = 0, int months = 0, int years = 0);
    QDuration &operator =(const QDuration &obj);

    // String conversions
    QString toString() const;
    static QDuration fromString(const QString &timeDurationString, const QString &dateDurationString);
    static QDuration fromString(const QString &durationString);

    // Add time units
    void addMilliseconds(int milliseconds);
    void addSeconds(int seconds);
    void addMinutes(int minutes);
    void addHours(int hours);
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);

    // Reset / copy
    void clearDuration();
    QDuration toDuration() const;

    // Getters
    int seconds() const;
    QTime getTime() const;
    bool isValid() const;

    int hours() const;
    int minutes() const;
    int days() const { return days_; }
    int months() const { return months_; }
    int years() const { return years_; }

    int toTimeSeconds(QTime time) const;
    int toTimeMilliseconds(QTime time) const;
    int toSeconds() const;
    int toMilliseconds() const;
    int toTimeSeconds() const;
    int toTimeMilliseconds() const;
private:
    int days_;
    int months_;
    int years_;
    QTime time_;
};

} // namespace QtDuration

#endif // QDURATION_H
