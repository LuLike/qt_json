#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

const QString FILENAME("plugin.json");

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //打开json文件plugin.json
    QDir dir(qApp->applicationDirPath());
    QString filePath=dir.cleanPath(dir.absolutePath()+QDir::separator()+FILENAME);
    QFile file(filePath);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        qDebug()<<"fail to open file "<<filePath<<endl;
        system("pause");
        return -1;
    }
    QByteArray ba=file.readAll();
    QJsonDocument jd=QJsonDocument::fromJson(ba);
    if(!jd.isObject())
    {
        qDebug()<<"json document is not a object"<<endl;
        system("pause");
        return -1;
    }
    QJsonObject jo=jd.object();
    if(!jo.contains(QString("category")))
    {
        qDebug()<<"json document is no arry category"<<endl;
        system("pause");
        return -1;
    }
    QJsonArray ja=jo.value(QString("category")).toArray();
    if(ja.count()<1)
    {
        qDebug()<<"arry category is null"<<endl;
        system("pause");
        return -1;
    }

    //解析json中的category数组
    //第一级 category
    for(auto itr=ja.begin();itr!=ja.end();++itr)
    {
        QJsonValue eachCategoyJsonValue=*itr;
        QJsonObject eachCategoyJsonObject=eachCategoyJsonValue.toObject();
        if(!eachCategoyJsonObject.contains(QString("sequenceNumber")))
        {
            qDebug()<<"this object is no sequenceNumber"<<endl;
            continue;
        }
       if(eachCategoyJsonObject.value(QString("sequenceNumber")).isNull())
       {
           qDebug()<<"sequenceNumber is null"<<endl;
           continue;
       }
        int eachCategoyId = eachCategoyJsonObject.value(QString("sequenceNumber")).toInt();

       if(!eachCategoyJsonObject.contains(QString("showText")))
       {
           qDebug()<<"this object is no showText"<<endl;
           continue;
       }
      if(eachCategoyJsonObject.value(QString("showText")).isNull())
      {
          qDebug()<<"showText is null"<<endl;
          continue;
      }
      QString eachCategoyText=eachCategoyJsonObject.value(QString("showText")).toString();

      if(!eachCategoyJsonObject.contains(QString("division")))
      {
          qDebug()<<"this object is no division"<<endl;
          continue;
      }
      QJsonArray divisionJsonArray = eachCategoyJsonObject.value(QString("division")).toArray();
      //第二级 division
      for(auto ditr=divisionJsonArray.begin();ditr!=divisionJsonArray.end();++ditr)
      {
          QJsonValue eachDivisionJsonValue=*ditr;
          QJsonObject eachDivisionJsonObject=eachDivisionJsonValue.toObject();
          if(!eachDivisionJsonObject.contains(QString("sequenceNumber")))
          {
              qDebug()<<"this object is no sequenceNumber"<<endl;
              continue;
          }
         if(eachDivisionJsonObject.value(QString("sequenceNumber")).isNull())
         {
             qDebug()<<"sequenceNumber is null"<<endl;
             continue;
         }
          int eachDivisionId=eachDivisionJsonObject.value(QString("sequenceNumber")).toInt();

          if(!eachDivisionJsonObject.contains(QString("showText")))
          {
              qDebug()<<"this object is no showText"<<endl;
              continue;
          }
         if(eachDivisionJsonObject.value(QString("showText")).isNull())
         {
             qDebug()<<"showText is null"<<endl;
             continue;
         }
          QString eachDivisionText=eachDivisionJsonObject.value(QString("showText")).toString();

          if(!eachDivisionJsonObject.contains(QString("icon")))
          {
              qDebug()<<"this object is no icon"<<endl;
              continue;
          }
         if(eachDivisionJsonObject.value(QString("icon")).isNull())
         {
             qDebug()<<"icon is null"<<endl;
             continue;
         }
          QString eachDivisionIcon=eachDivisionJsonObject.value(QString("icon")).toString();

          if(!eachDivisionJsonObject.contains(QString("section")))
          {
              qDebug()<<"this object is no section"<<endl;
              continue;
          }
           QJsonArray sectionJsonArray = eachDivisionJsonObject.value(QString("section")).toArray();
           //第三级 section
           for(auto sitr=sectionJsonArray.begin();sitr!=sectionJsonArray.end();++sitr)
           {
               QJsonValue eachSectionJsonValue=*sitr;
               QJsonObject eachSectionJsonObject=eachSectionJsonValue.toObject();
               if(!eachSectionJsonObject.contains(QString("sequenceNumber")))
               {
                   qDebug()<<"this object is no sequenceNumber"<<endl;
                   continue;
               }
              if(eachSectionJsonObject.value(QString("sequenceNumber")).isNull())
              {
                  qDebug()<<"sequenceNumber is null"<<endl;
                  continue;
              }
               int eachSectionId=eachSectionJsonObject.value(QString("sequenceNumber")).toInt();

               if(!eachSectionJsonObject.contains(QString("showText")))
               {
                   qDebug()<<"this object is no showText"<<endl;
                   continue;
               }
              if(eachSectionJsonObject.value(QString("showText")).isNull())
              {
                  qDebug()<<"showText is null"<<endl;
                  continue;
              }
               QString eachSectionText=eachSectionJsonObject.value(QString("showText")).toString();

               if(!eachSectionJsonObject.contains(QString("algorithmName")))
               {
                   qDebug()<<"this object is no algorithmName"<<endl;
                   continue;
               }
              if(eachSectionJsonObject.value(QString("algorithmName")).isNull())
              {
                  qDebug()<<"algorithmName is null"<<endl;
                  continue;
              }
               QString algorithmName=eachSectionJsonObject.value(QString("algorithmName")).toString();

               if(!eachSectionJsonObject.contains(QString("algorithmVersion")))
               {
                   qDebug()<<"this object is no algorithmVersion"<<endl;
                   continue;
               }
              if(eachSectionJsonObject.value(QString("algorithmVersion")).isNull())
              {
                  qDebug()<<"algorithmVersion is null"<<endl;
                  continue;
              }
               QString algorithmVersion=eachSectionJsonObject.value(QString("algorithmVersion")).toString();

               if(!eachSectionJsonObject.contains(QString("icon")))
               {
                   qDebug()<<"this object is no icon"<<endl;
                   continue;
               }
              if(eachSectionJsonObject.value(QString("icon")).isNull())
              {
                  qDebug()<<"icon is null"<<endl;
                  continue;
              }
               QString icon=eachSectionJsonObject.value(QString("icon")).toString();

               if(!eachSectionJsonObject.contains(QString("enable")))
               {
                   qDebug()<<"this object is no enable"<<endl;
                   continue;
               }
              if(eachSectionJsonObject.value(QString("enable")).isNull())
              {
                  qDebug()<<"enable is null"<<endl;
                  continue;
              }
               bool enable=eachSectionJsonObject.value(QString("enable")).toBool();
           }
      }
    }
     qDebug()<<"success to analysis"<<FILENAME<<endl;
     system("pause");
     return 1;
    //return a.exec();
}
