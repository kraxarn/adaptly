# QML files are in qml/
if (QT_KNOWN_POLICY_QTP0004)
	qt_policy(SET QTP0004 NEW)
endif ()

qt_add_qml_module(${PROJECT_NAME}
	URI ${PROJECT_NAME}_app
	VERSION ${PROJECT_VERSION}
	NO_RESOURCE_TARGET_PATH
	QML_FILES
	qml/Main.qml
	RESOURCES
)