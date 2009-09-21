/***************************************************************************
 *   Copyright (C) 2009 by Miguel Chavez Gamboa                            *
 *   miguel@mibit.com.mx                                                   *
 *   Mixedbits Software                                                    *
 *                                                                         *
 *   This is based on the KLineEdit class                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef MIBITLINEEDIT_H
#define MIBITLINEEDIT_H

#include <QLineEdit>
class QTimer;

class MibitLineEdit : public QLineEdit
{
  Q_OBJECT
  public:
    explicit MibitLineEdit( const QString &string, QWidget *parent = 0 );
    explicit MibitLineEdit( QWidget *parent = 0 );
    virtual ~MibitLineEdit();
    /**
     * This makes the line edit display a grayed-out hinting text as long as
     * the user didn't enter any text. It is often used as indication about
     * the purpose of the line edit.
     */
    void setEmptyMessage( const QString &msg );

    /**
     * @return the message set with setEmptyMessage
     */
    QString getEmptyMessage() const;

    /**
      * sets background color to indicate an error on input.
      */
    void setError( const QString& msg );

    /**
      * sets automatic clear of errors
      */
    void setAutoClearError( const bool& state );

  protected:
    virtual void paintEvent( QPaintEvent *ev );
    virtual void focusInEvent( QFocusEvent *ev );
    virtual void focusOutEvent( QFocusEvent *ev );

  private:
    QString emptyMessage;
    bool    drawEmptyMsg;
    bool    drawError;
    bool    autoClear;
    int     actualColor;
    QTimer  *timer;

  private slots:
    void    onTextChange(const QString &text);
    void    clearError();
    void    stepColors();
};

#endif // MibitLineEdit_H
