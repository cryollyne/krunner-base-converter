#include "base_converter_runner.hpp"
#include <KRunner/AbstractRunner>
#include <KLocalizedContext>
#include <KLocalizedString>
#include <QApplication>
#include <QClipboard>
#include <QIcon>
#include <QString>

BaseConverterRunner::BaseConverterRunner(QObject *parent, const KPluginMetaData &data)
    : AbstractRunner(parent, data)
{}

void BaseConverterRunner::init() {
    reloadConfiguration();
    connect(this, &KRunner::AbstractRunner::prepare, this, []() {

    });
    connect(this, &KRunner::AbstractRunner::teardown, this, []() {

    });
}

void BaseConverterRunner::match(KRunner::RunnerContext &context) {
    QString query = context.query();
    QString prefix = i18n("base ");
    if (!query.startsWith(prefix)) return;
    QStringList args = query.split(u' ');
    if (args.size() != 4) return;

    uint from =  args[1].toUInt();
    uint to =  args[2].toUInt();
    uint input = args[3].toUInt(nullptr, from);
    QString output = QString::number(input, to);

    KRunner::QueryMatch match(this);
    match.setIcon(QIcon::fromTheme(QLatin1String("edit-copy")));
    match.setText(output);

    context.addMatch(match);
}

void BaseConverterRunner::run(const KRunner::RunnerContext &context, const KRunner::QueryMatch &match) {
    (void)context;
    QClipboard *clip = QApplication::clipboard();
    clip->setText(match.text(), QClipboard::Mode::Clipboard);
}

void BaseConverterRunner::reloadConfiguration() {
}



K_PLUGIN_CLASS_WITH_JSON(BaseConverterRunner, "base_converter_runner.json")
#include "base_converter_runner.moc"
