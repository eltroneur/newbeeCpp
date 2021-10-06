    QTreeView *tv = new QTreeView(this);
    QStandardItemModel *model = new QStandardItemModel(this);

    QStandardItem *parentItem = model->invisibleRootItem();
    QStandardItem *curItem;
    for (int i = 0; i < 4; ++i)
    {
        curItem = new QStandardItem(QString("item %1").arg(i));
        parentItem->appendRow(curItem);
        parentItem = curItem;
    }

    tv->setModel(model);
    setCentralWidget(tv);
