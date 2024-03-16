#include <QApplication>

#include <QIcon>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

#include <QFormLayout>
#include <QVBoxLayout>

#include <QPixmap>
#include <QListWidget>
#include <QListWidgetItem>

#include <iostream>
using std::cerr;

int qLineEditExample(int argc, char *argv[]){
    QApplication a{argc, argv};

    QWidget w{};
    QLineEdit lineEdit;

    QLineEdit saySomethingLineEdit;
    QLabel sayLabel{"&Say something"};
    // The buddy mechanism is only available for QLabels that contain text in which one character is prefixed with an ampersand, &
    // This character, P in our example, is set as the shortcut key. So when the user presses ALT + S the mnemonic is triggered
    // By setting the saySomethingLineEdit as sayLabel's buddy, we are adding a mnemonic (ALT+S) that will set the keyboard focus to saySomethingLineEdit (its buddy)
    sayLabel.setBuddy(&saySomethingLineEdit);

    QVBoxLayout layout{ &w };
    layout.addWidget(&lineEdit); // this is the first line edit in the layout, so, by default, it has the keyboard focus
    layout.addWidget(&sayLabel);
    // we set the QLineEdit saySomethingLineEdit to be sayLabel "buddy".
    //Therefore, when the user presses ALT + S (note the name of the label: "&Say something", S is the shortcut character), saySomethingLineEdit gets keyboard focus
    layout.addWidget(&saySomethingLineEdit);


    //    // hey, we can also add an image to a label
    //    // compute the path of the image relative to the application's directory path
    //    QString imagePath = QApplication::applicationDirPath()+"/../images/tom.jpg";
    //    // the QPixmap class is an off-screen image representation, that will hold the image
    //    QPixmap pixmap = QPixmap(imagePath); // load the pixmap from a filepath
    //    QLabel labelImage{}; // the label that will display the image

    //    if(pixmap.isNull()){ // check that we succesfully loaded the image
    //        cerr<<"Failed to load image: "<<imagePath.toStdString();
    //    }else{
    //        // if succeeded, set the pixmap (i.e. the image) on the label
    //        labelImage.setPixmap(pixmap);
    //        // add this label (that now displays an image) to the layout
    //        layout.addWidget(&labelImage);
    //    }

    w.show();

    return a.exec();

}

int qPushButtonExample(int argc, char *argv[]){

    QApplication a(argc, argv);

    QPushButton button{"&This is a button.\nPush it!"}; // we use again mnemonics, T is the shortcut character in this case
    // when we press ALT+T the button is like we clicked on the button

    // set tooltip
    button.setToolTip("Hello! I'm a button!");
    button.setToolTipDuration(2000); // Specifies how long time the tooltip will be displayed, in millisecond. In our case, the button will be visible 2 seconds

    // let's change the font of the button!
    QFont font{"Courier", 50, 10, true}; // Create a new type of font with font family: Courier, pointSize - 50, weight - 10 and italic (last parameter of the constructor is a boolean controlling wether the font should be italic or not)
    button.setFont(font); // apply this new font on the button


    // also add an icon on the button
    QString imagePath{QApplication::applicationDirPath()+"/../images/tux.jpg"};
    QIcon icon{imagePath}; // create an icon that will store the image
    button.setIcon(icon);
    button.setIconSize(QSize(400, 400));

    button.show();

    return a.exec();

}

int qListWidgetExample(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QListWidget planetsList{};

    // get icons from resources (see resources.qrc file)
    new QListWidgetItem{QIcon{":/planets/sun.jpg"}, "Sun", &planetsList};
    new QListWidgetItem{QIcon{":/planets/mercury.jpg"}, "Mercury", &planetsList};
    new QListWidgetItem{QIcon{":/planets/venus.jpg"}, "Venus", &planetsList};
    new QListWidgetItem{QIcon{":/planets/earth.jpg"}, "Earth", &planetsList};
    new QListWidgetItem{QIcon{":/planets/callisto.jpg"}, "Callisto", &planetsList};
    new QListWidgetItem{QIcon{":/planets/jupiter.jpg"}, "Jupiter", &planetsList};
    new QListWidgetItem{QIcon{":/planets/saturn.jpg"}, "Saturn", &planetsList};
    new QListWidgetItem{QIcon{":/planets/uranus.jpg"}, "Uranus", &planetsList};
    new QListWidgetItem{QIcon{":/planets/neptune.jpg"}, "Neptune", &planetsList};
    planetsList.setIconSize(QSize(120, 120));

    for(int i = 0; i < planetsList.count(); i+=2) //we can iterate through the list items
    {
        QFont font("Courier", 20, 10, true);
        QListWidgetItem *item = planetsList.item(i); // we get the list item at position i
        item->setFont(font); // we chnage the font of this list item (only of the even indices: note that i  in {0, 2, 4, ...}
    }

    // we can also have a list item without an icon
    new QListWidgetItem{"PSO-J380", &planetsList};


    planetsList.setGeometry(0, 0, 800, 600);
    planetsList.show();
    planetsList.setWindowTitle("Planets in the solar system");
    // we can check for the selected index in the list. we can also programatically set the current index.
    cerr<<"The selected item in the list is: "<<planetsList.currentRow()<<'\n';
    planetsList.setCurrentRow(2);
    cerr<<"The selected item in the list is: "<<planetsList.currentRow()<<'\n';
    return a.exec();
}

int hBoxLayoutExample(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wnd{};
    QHBoxLayout hLay{};
    QPushButton btn1{ "Button 1" };
    QPushButton btn2{ "Button 2" };
    QPushButton btn3{ "Button 3" };
    hLay.addWidget(&btn1); // the buttons will be aligned horizontally, i.e. one next to the other: btn1 | btn2 | btn3
    hLay.addWidget(&btn2);
    hLay.addWidget(&btn3);
    wnd.setLayout(&hLay);
    wnd.show();

    return a.exec();
}

int vBoxLayoutExample(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *wnd = new QWidget{};
    QVBoxLayout *vLay = new QVBoxLayout{};
    QPushButton *btn1 = new QPushButton{ "Button 1" };
    QPushButton *btn2 = new QPushButton{ "Button 2" };
    QPushButton *btn3 = new QPushButton{ "Button 3" };
    vLay->addWidget(btn1); // the buttons will be aligned vertically: i.e. btn1 is at the top of the widget, btn2 is below btn1, btn3 is below btn2
    vLay->addWidget(btn2);
    vLay->addWidget(btn3);
    wnd->setLayout(vLay);
    wnd->show();

    return a.exec();
}

int formLayoutExample(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFormLayout *formLayout{new QFormLayout{}};

    // create labels and textboxes
    // name label and lineedit
    QLineEdit* nameLineEdit{new QLineEdit{}};
    QLabel* nameLabel{new QLabel{ "&Name:" }};
    nameLabel->setBuddy(nameLineEdit);

    // age label and lineedit
    QLineEdit* ageLineEdit{new QLineEdit{}};
    QLabel* ageLabel{new QLabel{ "&Age:" }};
    ageLabel->setBuddy(ageLineEdit);

    // email label and lineedit
    QLineEdit* emailLineEdit{new QLineEdit{}};
    QLabel* emailLabel{new QLabel{ "&Email:" }};
    emailLabel->setBuddy(emailLineEdit);

    // add the name, age and email rows to the form layout
    formLayout->addRow(nameLabel, nameLineEdit);
    formLayout->addRow(ageLabel, ageLineEdit);
    formLayout->addRow(emailLabel, emailLineEdit);


    QWidget *wnd{new QWidget{}};
    // apply the form layout on the "main" widget
    wnd->setLayout(formLayout);
    wnd->show();

    return a.exec();
}

int gridLayoutExample(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGridLayout *gridLayout = new QGridLayout{};

    // add some buttons
    // the add button is added at row 0, column 0
    gridLayout->addWidget(new QPushButton("Add"), 0, 0);
    // the delete button is added at row 0, column 1
    gridLayout->addWidget(new QPushButton("Delete"), 0, 1);
    // the update button is added at row 0, column 2
    gridLayout->addWidget(new QPushButton("Update"), 0, 2);
    // the filter button is added at row 1, column 1
    gridLayout->addWidget(new QPushButton("Filter"), 1, 1);
    // it is also possible for a widget to occupy multiple cells using the row and column spanning
    // row span = 1, column span = 3
    // the sort button is added at row 2, column 0, at it spans 1 row and 3 columns
    gridLayout->addWidget(new QPushButton("Sort"), 2, 0, 1, 3);

    //  add     delete      update
    //          filter
    // -----------sort-------------

    QWidget *window = new QWidget{};
    window->setLayout(gridLayout);
    window->setWindowTitle("GridLayoutExample");
    window->show();

    return a.exec();
}



int nameInputExampleAbsolutePositioning(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget main{};
    QLabel nameLabel{"Name:", &main};
    nameLabel.setGeometry(10, 10, 40, 20); // absolute positioning: the label will always be positioned at x: 10, y: 10 and will have width:40 and height: 20, regardless of the widget size
    QLineEdit nameTxt{&main};
    nameTxt.setGeometry(60, 10, 100, 20); // absolute positioning: the textedit will always be positioned at x: 60, y: 10 and will have width:100 and height: 20
    main.show();
    main.setWindowTitle("Absolute positioning");

    return a.exec();
}

int nameInputExampleWithLayouts(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *main{new QWidget{}};
    QFormLayout *formLayout{new QFormLayout{main}};
    QLabel* nameLabel = new QLabel("Name:", main);
    QLineEdit* nameTxt = new QLineEdit(main);
    formLayout->addRow(nameLabel, nameTxt); // adds a new row to the bottom of this form layout, with the given label and field.
    main->show();
    main->setWindowTitle("Layout");
    // fix the height to the "ideal" height
    main->setFixedHeight(main->sizeHint().height());	// Sets both the minimum and maximum heights of the widget to the given height.
    // sizeHint - holds the recommended size for the widget.

    return a.exec();
}

int multipleLayoutsExample(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget{};
    QVBoxLayout *verticalLayout = new QVBoxLayout{};
    window->setLayout(verticalLayout); // all the elements from the window will be aligned vertically
    window->setWindowTitle("MultipleLayoutsExample");

    // create an information widget, which uses a form layout
    QWidget *detailsWidget = new QWidget{};
    QFormLayout *formLayout = new QFormLayout{};
    detailsWidget->setLayout(formLayout);

    // name row
    QLabel *labelName = new QLabel{ "&Name" };
    QLineEdit *nameTxt = new QLineEdit{};
    labelName->setBuddy(nameTxt);
    formLayout->addRow(labelName, nameTxt);

    // age row
    QLabel *labelAge = new QLabel{ "&Age" };
    QLineEdit *ageTxt = new QLineEdit{};
    labelAge->setBuddy(ageTxt);
    formLayout->addRow(labelAge, ageTxt);

    // add the information widget to the window (remember, this uses a vertical layout)
    verticalLayout->addWidget(detailsWidget);

    // create a widget with two buttons for two possible actions: Save or Cancel
    // this widget will have a QHBoxLayout
    QWidget* actions = new QWidget{};
    QHBoxLayout* horizontalLayout = new QHBoxLayout{};
    QPushButton *cancelBtn = new QPushButton{ "&Cancel" };
    QPushButton *saveBtn = new QPushButton{ "&Save" };
    horizontalLayout->addWidget(saveBtn);
    horizontalLayout->addWidget(cancelBtn);
    actions->setLayout(horizontalLayout);

    // add the actions widget to the window  (remember, this uses a vertical layout, so it will be positioned below the information widget)
    verticalLayout->addWidget(actions);

    //show window
    window->show();

    return a.exec();
}


int main(int argc, char *argv[])
{
    //    return qLineEditExample(argc, argv);
    //    return qPushButtonExample(argc, argv);
    return qListWidgetExample(argc, argv);

    //    return hBoxLayoutExample(argc, argv);
    //    return vBoxLayoutExample(argc, argv);
    //    return formLayoutExample(argc, argv);
    //    return gridLayoutExample(argc, argv);
    //    return nameInputExampleAbsolutePositioning(argc, argv);
    //    return nameInputExampleWithLayouts(argc, argv);

    //    return multipleLayoutsExample(argc, argv);

}
