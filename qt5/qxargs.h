#pragma once

#include <QObject>
#include <QtCore>

class QXArgs : public QObject {
	Q_OBJECT

public:
	QXArgs(QStringList spec,QObject *parent = nullptr);
	bool parse(QStringList args);
	~QXArgs();

private:
	QStringList spec;
	QCommandLineParser parser;
	QHash<QCommandLineOption, QString> type_hash;
};
