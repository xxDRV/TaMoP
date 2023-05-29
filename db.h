#ifndef DB_H
#define DB_H

#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>


class DataBase;
/**
 * @brief The DataBaseDestroyer class класс для очистки базы данных.
 */
class DataBaseDestroyer
{
    private:
        DataBase *instance;
    public:
        ~DataBaseDestroyer() { delete instance; }
        void initialize(DataBase *link){ instance = link; }
};
/**
 * @brief The DataBase class класс для базы данных
 */
class DataBase
{
    private:
        static DataBase *instance;
        static DataBaseDestroyer destroyer;
        QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    protected:
        DataBase()
        {
            DB.setDatabaseName("../Tcp_server_v3/DB.db");

            if(!DB.open())
            {
                qDebug()<<"Error opening DataBase";
                std::exit(1);
            }
        }
        DataBase(const DataBase &) = delete;
        DataBase &operator = (DataBase &) = delete;
        ~DataBase() { DB.close(); }
        friend class DataBaseDestroyer;
    public:
        /**
         * @brief query_execute  функция, которая выполняет запросы.
         * @param query_list список запросов.
         * @return возвращает результат.
         */
        QString query_execute(QList<QString> query_list)
        {
            QSqlQuery query(DB);
            query.prepare(query_list[0]);
            query_list.pop_front();
            while(!query_list.isEmpty())
            {
                query.bindValue(query_list[0],query_list[1]);
                query_list.pop_front();
                query_list.pop_front();
            }

            query.exec();

            QString result;
            QSqlRecord record = query.record();
            int column_count = record.count();

            while (query.next())
            {
                for (int i = 0; i < column_count; ++i)
                {
                    result.append(query.value(i).toString());
                    if (i < column_count - 1)
                    {
                        result.append(",");
                    }
                }
                result.append(";");
            }
            return result;
        }
        /**
         * @brief Connect подключение базы данных.
         * @return возвращает базу данных.
         */
        static DataBase *Connect(){
            if (!instance)
            {
                instance = new DataBase();
                destroyer.initialize(instance);
            }
            return instance;
        }
};

DataBase *DataBase::instance;
DataBaseDestroyer DataBase::destroyer;

#endif // DB_H
