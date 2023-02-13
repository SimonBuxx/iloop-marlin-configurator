#ifndef ABSTRACTPAGE_H
#define ABSTRACTPAGE_H

#include <QWidget>

class AbstractPage : public QWidget
{
    Q_OBJECT
public:
    explicit AbstractPage(QWidget *pParent = nullptr);

    virtual void Init(void);

    /// \brief Resets all parameters on the page to their defaults
    virtual void ResetValues(void) = 0;

    /// \brief Loads the page parameters from the given JSON object
    ///
    /// \param pJson: Reference to the JSON object
    /// \return \b true, if all expected parameters where found in the JSON
    virtual bool LoadFromJson(const QJsonObject &pJson) = 0;

    virtual void ReplaceTags(QStringList& pOutput) = 0;

public slots:
    virtual void OnUpdatePreview(void);

protected:
    /// \brief Connects this widget's signals and slots
    virtual void ConnectGuiSignalsAndSlots(void);

signals:
    void UpdatePreviewSignal(const QStringList& pOutput);

protected:
    std::optional<QStringList> mTemplate;
};

#endif // ABSTRACTPAGE_H
