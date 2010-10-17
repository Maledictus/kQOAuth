/**
 * KQOAuth - An OAuth authentication library for Qt.
 *
 * Author: Johan Paul (johan.paul@gmail.com)
 *         http://www.johanpaul.com
 *
 *  KQOAuth is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  KQOAuth is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with KQOAuth.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef FT_KQOAUTH_H
#define FT_KQOAUTH_H

#include <QObject>
#include <QEventLoop>

class MyEventLoop : public QEventLoop
{
    Q_OBJECT
public:
    bool timeout() const;
    int exec( ProcessEventsFlags flags = AllEvents );
public slots:
    void quitWithTimeout();
private:
    bool m_timeout;
};

class KQOAuthRequest;
class KQOAuthManager;
class Ft_KQOAuth : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void init();
    void cleanup();
    void constructor();

    void ft_getRequestToken_data();
    void ft_getRequestToken();

private:
    KQOAuthRequest *request;
    KQOAuthManager *manager;

};

#endif // FT_KQOAUTH_H
