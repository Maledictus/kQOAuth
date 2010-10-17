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
#ifndef KQOAUTHMANAGER_H
#define KQOAUTHMANAGER_H

#include <QObject>

class KQOAuthRequest;
class KQOAuthManagerThread;
class KQOAuthManagerPrivate;
class QNetworkReply;
class KQOAuthManager : public QObject
{
    Q_OBJECT
public:
    explicit KQOAuthManager(QObject *parent = 0);
    ~KQOAuthManager();

    void executeRequest(KQOAuthRequest *request);

signals:
    void requestReady();

public slots:

private slots:
    void onRequestDone(QNetworkReply *);

private:
    KQOAuthManagerPrivate *d_ptr;
    Q_DECLARE_PRIVATE(KQOAuthManager);

    KQOAuthRequest *r;
    KQOAuthManagerThread *t;
};

#endif // KQOAUTHMANAGER_H
