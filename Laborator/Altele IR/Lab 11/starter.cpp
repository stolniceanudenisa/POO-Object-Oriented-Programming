#include <QFile>
#include <QDebug>
#include <QString>
#include <QVector>
#include <QApplication>


class Book{
public:
    Book() = default;
    Book(QString title, QString author, QString genre, int height, QString publisher){
        m_title =  title;
        m_author = author;
        m_genre = genre;
        m_height = height;
        m_publisher = publisher;
    }
    friend QDebug operator<< (QDebug d, const Book &book); // to be able to use Book with qDebug()

private:
    QString m_title;
    QString m_author;
    QString m_genre;
    int m_height;
    QString m_publisher;
};


QDebug operator<<(QDebug d, const Book &book) {
    d << book.m_title<<book.m_author<<book.m_genre<<book.m_height<<book.m_publisher;
    return d;
}

bool loadBooks(QString filepath, QVector<Book>& books){
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "ERROR! "<<file.errorString();
        return false;
    }

    quint32 lineNo{0};
    while (!file.atEnd()) {
        QString line = file.readLine().trimmed();

        if(lineNo == 0){ // ignore header
            lineNo++;
            continue;
        }
        QStringList lineElements = line.split(',');
        assert(lineElements.size() == 5);
        Book book{lineElements.at(0), lineElements.at(1), lineElements.at(2),
                    lineElements.at(3).toInt(), lineElements.at(4)};

        books.push_back(book);
        lineNo++;
    }


    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector<Book> books;

    bool loaded = loadBooks("books.csv", books);
    Q_UNUSED(loaded)

    qDebug()<<"Loaded "<<books.size()<<" books";
    for(Book b: books){
        qDebug()<<b;
    }
    return a.exec();
}


