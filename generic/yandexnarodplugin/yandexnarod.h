/*
    yandexnarodPlugin

	Copyright (c) 2008-2009 by Alexander Kazarin <boiler@co.ru>
		      2011 Evgeny Khryukin

 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************
*/

#ifndef YANDEXNARODPLUGIN_H
#define YANDEXNARODPLUGIN_H

class QAction;

#include "psiplugin.h"
#include "optionaccessinghost.h"
#include "optionaccessor.h"
#include "menuaccessor.h"
#include "iconfactoryaccessinghost.h"
#include "iconfactoryaccessor.h"
#include "stanzasender.h"
#include "stanzasendinghost.h"
#include "plugininfoprovider.h"
#include "applicationinfoaccessinghost.h"
#include "applicationinfoaccessor.h"

class yandexnarodSettings;
class uploadDialog;
class yandexnarodManage;


class yandexnarodPlugin : public QObject, public PsiPlugin, public OptionAccessor, public MenuAccessor, public IconFactoryAccessor
			, public StanzaSender, public PluginInfoProvider, ApplicationInfoAccessor
{
	Q_OBJECT
	Q_INTERFACES(PsiPlugin OptionAccessor MenuAccessor IconFactoryAccessor StanzaSender PluginInfoProvider ApplicationInfoAccessor)

public:
	yandexnarodPlugin();
	virtual QString name() const;
	virtual QString shortName() const;
	virtual QString version() const;
	virtual QWidget* options();
	virtual bool enable();
	virtual bool disable();
	virtual void setOptionAccessingHost(OptionAccessingHost* host);
	virtual void setIconFactoryAccessingHost(IconFactoryAccessingHost* host);
	virtual void setStanzaSendingHost(StanzaSendingHost* host);
	virtual void setApplicationInfoAccessingHost(ApplicationInfoAccessingHost* host);
	virtual void optionChanged(const QString& /*option*/) {};
	virtual void applyOptions();
	virtual void restoreOptions();
	virtual QList < QVariantHash > getAccountMenuParam();
	virtual QList < QVariantHash > getContactMenuParam();
	virtual QAction* getContactAction(QObject* /*parent*/, int /*account*/, const QString& /*contact*/) { return 0; };
	virtual QAction* getAccountAction(QObject* /*parent*/, int /*account*/) { return 0; };
	virtual QString pluginInfo();

private:
	OptionAccessingHost* psiOptions;
	IconFactoryAccessingHost* psiIcons;
	StanzaSendingHost* stanzaSender;
	ApplicationInfoAccessingHost* appInfo;
	bool enabled;
	QString currentJid;
	int currentAccount;

	QPointer<uploadDialog> uploadwidget;
	QPointer<yandexnarodSettings> settingswidget;
	QPointer<yandexnarodManage> manageDialog;
	QFileInfo fi;


private slots:
	void manage_clicked();
	void on_btnTest_clicked();
	void on_TestFinished();
	void actionStart();
	void onFileURL(const QString& url);
};

#endif
