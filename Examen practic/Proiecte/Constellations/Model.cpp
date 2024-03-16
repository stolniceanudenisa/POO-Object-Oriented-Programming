#include "Model.h"

int Model::rowCount(const QModelIndex& parent) const
{
	return this->repository.getAll().size();
}

int Model::columnCount(const QModelIndex& parent) const
{
	return 5;
}

QVariant Model::data(const QModelIndex& index, int role) const
{
	int row = index.row();
	int column = index.column();
	Star current = this->repository.getAll()[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(current.getName());
		case 1:
			return QString::fromStdString(current.getConstellation());
		case 2:
			return QString::number(current.getRA());
		case 3:
			return QString::number(current.getDec());
		case 4:
			return QString::number(current.gerDiameter());
		}
	}

	return QVariant();
}

QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString("Name");
			case 1:
				return QString("Constellation");
			case 2:
				return QString("RA");
			case 3:
				return QString("Dec");
			case 4:
				return QString("Diameter");
			}
		}
	}
	return QVariant();
}

void Model::update()
{
	emit layoutAboutToBeChanged();
	emit layoutChanged();
}


