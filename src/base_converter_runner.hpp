#ifndef INCLUDE_SRC_BASE_CONVERTER_RUNNER_HPP_
#define INCLUDE_SRC_BASE_CONVERTER_RUNNER_HPP_

#include <KRunner/AbstractRunner>

class BaseConverterRunner : public KRunner::AbstractRunner {
    Q_OBJECT

public:
    BaseConverterRunner(QObject *parent, const KPluginMetaData &data);
    void match(KRunner::RunnerContext &context) override;
    void run(const KRunner::RunnerContext &context, const KRunner::QueryMatch &match) override;
    void reloadConfiguration() override;

protected:
    void init() override;

};

#endif  // INCLUDE_SRC_BASE_CONVERTER_RUNNER_HPP_
