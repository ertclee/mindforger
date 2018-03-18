/*
 look_n_feel.h     MindForger thinking notebook

 Copyright (C) 2016-2018 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef M8RUI_LOOK_N_FEEL_H
#define M8RUI_LOOK_N_FEEL_H

#include <QtWidgets>
#include <QSet>

#include "../../lib/src/config/configuration.h"

namespace m8r {

/**
 * @brief L&F singleton class.
 *
 * The reason to make this class singleton is that it's used through frontend
 * components and widgets. Therefore passing of L&F instance to each and every
 * instance of the GUI object tree would be inefficient.
 */
class LookAndFeels
{
public:
    static LookAndFeels& getInstance()
    {
        static LookAndFeels SINGLETON{};
        return SINGLETON;
    }
private:
    explicit LookAndFeels();

private:
    /**
     * @brief Active palette.
     */
    QPalette palette;
    /**
     * @brief Active stylesheet.
     */
    char* stylesheet;

    QSet<QString> themeNames;

    int fontPointSize;

private:
    QApplication* mindforgerApplication;

    // viewer
    QString textColor;

    // editor
    QString editorBackgroundColor;
    QString editorLineNumbersForegroundColor;
    QString editorLineNumbersBackgroundColor;

    QColor editorBold;
    QColor editorBolder;
    QColor editorItalic;
    QColor editorItalicer;
    QColor editorStrikethrough;
    QColor editorLink;
    QColor editorCodeblock;
    QColor editorList;
    QColor editorHtmlTag;
    QColor editorHtmlEntity;
    QColor editorHtmlAttrName;
    QColor editorHtmlAttrValue;
    QColor editorHtmlComment;

    // CLI
    QColor cliTextColor;

public:
    LookAndFeels(const LookAndFeels&) = delete;
    LookAndFeels(const LookAndFeels&&) = delete;
    LookAndFeels &operator=(const LookAndFeels&) = delete;
    LookAndFeels &operator=(const LookAndFeels&&) = delete;

    /* Dark theme is supposed to be terminal (dark&green)
     * "hacker" style view suitable in the night and early
     * mornings when your eyes prefer less light.
     */
    void setDarkTheme();

    /* Light theme aims to be distraction-free Kindle style
     * theme suitable for comfortable knowledge reading and
     * navigation.
     */
    void setLightTheme();

    /* Extra (custom) theme(s)...
     */
    void setBlackTheme();

    void init(QApplication* mindforgerApplication);
    bool isThemeNameValid(const QString&) const;
    void setFontPointSize(int fontPointSize) { this->fontPointSize = fontPointSize; }
    int getFontPointSize() const { return fontPointSize; }
    void setTheme(const QString&);

    const QString& getTextColor() const { return textColor; }
    const QString& getEditorBackgroundColor() const { return editorBackgroundColor; }

    const QString& getEditorLineNumbersForegroundColor() const { return editorLineNumbersForegroundColor; }
    const QString& getEditorLineNumbersBackgroundColor() const { return editorLineNumbersBackgroundColor; }

    QColor& getEditorBold() { return editorBold; }
    QColor& getEditorBolder() { return editorBolder; }
    QColor& getEditorItalic() { return editorItalic; }
    QColor& getEditorItalicer() { return editorItalicer; }
    QColor& getEditorStrikethrough() { return editorStrikethrough; }
    QColor& getEditorLink() { return editorLink; }
    QColor& getEditorList() { return editorList; }
    QColor& getEditorCodeblock() { return editorCodeblock; }
    QColor& getEditorHtmlTag() { return editorHtmlTag; }
    QColor& getEditorHtmlEntity() { return editorHtmlEntity; }
    QColor& getEditorHtmlAttrName() { return editorHtmlAttrName; }
    QColor& getEditorHtmlAttrValue() { return editorHtmlAttrValue; }
    QColor& getEditorHtmlComment() { return editorHtmlComment; }

    const QColor& getCliTextColor() const { return cliTextColor; }
};

}

#endif // M8RUI_LOOK_N_FEEL_H