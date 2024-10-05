#include <QApplication>
#include <QTabWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QPalette>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QSettings>  // 用於儲存設定
#include <QVariant>   // 用於 QVariant

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 創建 QSettings 來保存和恢復設定
    QSettings settings("MyCompany", "MyApp");

    QTabWidget *tabWidget = new QTabWidget;

    // 創建第一個頁籤
    QWidget *tab1 = new QWidget;
    QVBoxLayout *layout1 = new QVBoxLayout;
    QLabel *label1 = new QLabel("隊長: 41243235 陳佳源\n組員1: 41243216 李宗燁\n組員2: 41243143 曾兆銘\n組員3: 41243108 鄭又瑄\n");

    // 從設定中恢復上次選擇的顏色
    QColor savedColor = qvariant_cast<QColor>(settings.value("labelColor", QColor(Qt::black))); // 使用 qvariant_cast 轉換 QVariant 到 QColor
    QPalette palette = label1->palette();
    palette.setColor(QPalette::WindowText, savedColor);
    label1->setPalette(palette);

    // 從設定中恢復上次選擇的字體
    QFont savedFont = qvariant_cast<QFont>(settings.value("labelFont", label1->font())); // 使用 qvariant_cast 轉換 QVariant 到 QFont
    label1->setFont(savedFont);

    layout1->addWidget(label1);
    tab1->setLayout(layout1);

    
    // 將頁籤加入 QTabWidget
    tabWidget->addTab(tab1, "Tab 1");
    tabWidget->addTab(tab2, "Tab 2");
    tabWidget->addTab(tab3, "Tab 3");
    tabWidget->addTab(tab4, "Tab 4");

    tabWidget->setWindowTitle("Qt Tab");
    tabWidget->resize(400, 300);
    tabWidget->show();

    return app.exec();
}
