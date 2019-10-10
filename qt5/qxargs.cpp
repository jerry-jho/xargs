#include "qxargs.h"

QXArgs::QXArgs(QStringList spec, QObject *parent)
	: QObject(parent) {
	QString spec_item;
	foreach(spec_item, spec) {
		QStringList spec_item_defs = spec_item.split("\t");
		// -f,--foo \t s|i|b|fr|fw \t <default> \t <doc>
		QString optionName    = spec_item_defs.at(0);
		QString optionType    = spec_item_defs.size() == 1 ? "b" : spec_item_defs.at(1);
		QString optionDefault = spec_item_defs.size() == 2 ? QString() : spec_item_defs.at(2);
		QString optionDoc     = spec_item_defs.size() == 3 ? QString() : spec_item_defs.at(3);
		QCommandLineOption    option(optionName.split(","), optionDoc);
		if (optionType != "b") {
			option.setValueName(optionName);
		}
		type_hash[option] = optionType;
		parser.addOption(option);
	}
}

QXArgs::~QXArgs() {
}

bool QXArgs::parse(QStringList args) {
	if (parser.parse(args)) {
		QHashIterator<QCommandLineOption, QString> i(type_hash);
		while (i.hasNext()) {
			i.next();
			if (parser.isSet(i.key())) {
				switch (i.value()) {
					"s" : 
				}
			}
			cout <<  << ": " << i.value() << endl;
		}
	}
}
