include(D:/PERSONAL-BudgetTrackerAppGUI/BudgetTrackerGUIApp/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/BudgetTrackerGUIApp-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE D:/PERSONAL-BudgetTrackerAppGUI/BudgetTrackerGUIApp/build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/BudgetTrackerGUIApp.exe
    GENERATE_QT_CONF
)
