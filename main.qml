import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView {
        id: listView
        x: 181
        y: 87
        width: 110
        height: 160
        model: filtro
        delegate: Item {

            width: 160
            height: 40

            Rectangle{
              width:80
              height: parent.height
              anchors.left: parent.left
              border.width: 3
              border.color: "transparent"
              color: "lightBlue"
              Text {
                  id: name
                  text: nomePar
                  anchors.fill: parent
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  color: "white"
                  font.pixelSize: 20
              }

            }

            Rectangle{
              width:80
              height: parent.height
              anchors.right: parent.right
              border.width: 3
              border.color: "transparent"
              color: "blue"
              Text {
                  id: val
                  text: Value
                  anchors.fill: parent
                  horizontalAlignment: Text.AlignHCenter
                  verticalAlignment: Text.AlignVCenter
                  color: "white"
                  font.pixelSize: 20
              }
              MouseArea {
               anchors.fill: parent
               onClicked:{

                   Value=8    // facendo cosi richiamo la setdata del filtro  metodo diretto

                   var column_number = 0;
                   // get `QModelIndex`
                   var q_model_index = filtro.index(index+1, column_number);


                   // see for list of roles:
                   // http://doc.qt.io/qt-5/qabstractitemmodel.html#roleNames
                   var role = 258 // valore dell'enum value

                   var data_changed = filtro.setData(q_model_index, 7, role);


                   console.log("data change successful?", data_changed);
                   console.log(filtro.data(q_model_index,261))  // stampo il valorelegato al role 261 va messa l'enum

               }
              }
            }
        }
    }

     ComboBox {
         id: comboBox
         x: 463
         y: 75
         model: filtro.data(filtro.index(1, 0),263) //[ "Forno Tronik", "Forno 1", "Forno 2" ]

         onCurrentIndexChanged: filtro.tipoFornoSel=currentIndex
     }
}
