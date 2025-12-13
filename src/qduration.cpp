#include <QDuration>

Q_DURATION_BEGIN_NAMESPACE

QDebug operator<<(QDebug dbg, const QDuration &duration)
{
    dbg.nospace() << "QDuration("
                  << duration.years() << " Years,"
                  << duration.months() << " Months,"
                  << duration.days() << " Days,"
                  << duration.getTime().toString("hh:mm:ss:zzz") << " "
                  << duration.toSeconds() << "s)";
    return dbg.space();
}

QDuration::QDuration():
    days_(0),
    months_(0),
    years_(0),
    time_(QTime(0, 0, 0, 0))
{
}

QDuration::QDuration(QTime time, int days, int months, int years):
    days_(0),
    months_(0),
    years_(0),
    time_(time)
{
    addYears(years);
    addMonths(months);
    addDays(days);
}


QString QDuration::toString() const
{
    return QString("%1-%2-%3 %4")
    .arg(years_)
        .arg(months_)
        .arg(days_)
        .arg(time_.toString("hh:mm:ss:zzz"));
}

QDuration QDuration::fromString(const QString &timeDurationString, const QString &dateDurationString)
{
    QDuration duration;
    QStringList datePieces = dateDurationString.split("-");
    if (datePieces.size() == 3) {
        duration.addYears(datePieces[0].toInt());
        duration.addMonths(datePieces[1].toInt());
        duration.addDays(datePieces[2].toInt());
    }
    duration.time_ = QTime::fromString(timeDurationString, "hh:mm:ss:zzz");
    return duration;
}

QDuration QDuration::fromString(const QString &durationString)
{
    QDuration duration;
    if (!durationString.isEmpty()) {
        QStringList parts = durationString.split(" ");
        if (parts.size() == 2) {
            QStringList datePieces = parts[0].split("-");
            if (datePieces.size() == 3) {
                duration.addYears(datePieces[0].toInt());
                duration.addMonths(datePieces[1].toInt());
                duration.addDays(datePieces[2].toInt());
            }
            duration.time_ = QTime::fromString(parts[1], "hh:mm:ss:zzz");
        }
    }
    return duration;
}

QDuration QDuration::toDuration() const
{
    return *this;
}

int QDuration::seconds() const
{
    return time_.second();
}

int QDuration::toSeconds() const
{
    return years_ * YEAR_SECONDS +
           months_ * MONTH_SECONDS +
           days_ * DAY_SECONDS +
           toTimeSeconds();
}

int QDuration::toMilliseconds() const
{
    return seconds() * 1000 + toTimeMilliseconds();
}

int QDuration::toTimeSeconds() const
{
    return time_.hour() * HOUR_SECONDS +
           time_.minute() * MINUTE_SECONDS +
           time_.second();
}

int QDuration::toTimeSeconds(QTime time) const
{
    return time.hour() * HOUR_SECONDS +
           time.minute() * MINUTE_SECONDS +
           time.second();
}

int QDuration::toTimeMilliseconds() const
{
    return time_.hour() * HOUR_SECONDS * 1000 +
           time_.minute() * MINUTE_SECONDS * 1000 +
           time_.second() * 1000 +
           time_.msec();
}

int QDuration::toTimeMilliseconds(QTime time) const
{
    return time.hour() * HOUR_SECONDS * 1000 +
           time.minute() * MINUTE_SECONDS * 1000 +
           time.second() * 1000 +
           time.msec();
}

// Adders
void QDuration::addYears(int years)
{
    years_ += years;
    if (years_ > 67) years_ -= 67; // keep max 67
}

void QDuration::addMonths(int months)
{
    months_ += months;
    if (months_ >= 12) {
        addYears(months_ / 12);
        months_ %= 12;
    }
}

void QDuration::addDays(int days)
{
    days_ += days;
    if (days_ >= 30) {
        addMonths(days_ / 30);
        days_ %= 30;
    }
}

void QDuration::addHours(int hours)
{
    if (hours <= 0) return;

    QTime oldTime = time_;
    time_ = time_.addSecs(hours * HOUR_SECONDS);
    if (toTimeSeconds(oldTime) >= toTimeSeconds()) addDays(1);

    if (hours >= 24) {
        addDays(hours / 24);
        addHours(hours % 24);
    }
}

void QDuration::addMinutes(int minutes)
{
    if (minutes <= 0) return;

    QTime oldTime = time_;
    time_ = time_.addSecs(minutes * MINUTE_SECONDS);
    if (toTimeSeconds(oldTime) >= toTimeSeconds()) addDays(1);

    if (minutes >= 60) {
        addHours(minutes / 60);
        addMinutes(minutes % 60);
    }
}

void QDuration::addSeconds(int seconds)
{
    if (seconds <= 0) return;

    QTime oldTime = time_;
    time_ = time_.addSecs(seconds);
    if (toTimeSeconds(oldTime) >= toTimeSeconds()) addDays(1);

    if (seconds >= 60) {
        addMinutes(seconds / 60);
        addSeconds(seconds % 60);
    }
}

void QDuration::addMilliseconds(int milliseconds)
{
    if (milliseconds <= 0) return;

    QTime oldTime = time_;
    time_ = time_.addMSecs(milliseconds);
    if (toTimeMilliseconds(oldTime) >= toTimeMilliseconds()) addDays(1);

    if (milliseconds >= 1000) {
        addSeconds(milliseconds / 1000);
        addMilliseconds(milliseconds % 1000);
    }
}

void QDuration::clearDuration()
{
    years_ = months_ = days_ = 0;
    time_ = QTime(0, 0, 0, 0);
}

bool QDuration::isValid() const
{
    return time_.isValid() &&
           years_ >= 0 && years_ <= 67 &&
           months_ >= 0 && months_ < 12 &&
           days_ >= 0 && days_ < 30;
}

int QDuration::hours() const
{
    return time_.hour();
}

int QDuration::minutes() const
{
    return time_.minute();
}

QTime QDuration::getTime() const
{
    return time_;
}

Q_DURATION_END_NAMESPACE
