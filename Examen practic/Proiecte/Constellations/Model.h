#pragma once
#include <qabstractitemmodel.h>

#include "Repository.h"


class Model : public QAbstractTableModel
{
private:
	Repository<Star>& repository;

public:
	Model(Repository<Star>& repo) : repository(repo) {}

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

	void update();

};
