#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace
{
	void defineTypes()
	{
	}
}

auto main(int argc, char *argv[]) -> int
{
#ifdef Q_OS_ANDROID
	// Workaround for https://bugreports.qt.io/browse/QTBUG-82617
	qputenv("QT_ANDROID_NO_EXIT_CALL", "1");
#endif

	QCoreApplication::setApplicationName(QStringLiteral(APP_NAME));
	QCoreApplication::setApplicationVersion(QStringLiteral(APP_VERSION));
	QCoreApplication::setOrganizationName(QStringLiteral(ORG_NAME));

	const QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	defineTypes();

	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &app, []
	{
		QCoreApplication::exit(-1);
	},Qt::QueuedConnection);

	engine.load(QStringLiteral(":/qml/Main.qml"));

	return QGuiApplication::exec();
}
