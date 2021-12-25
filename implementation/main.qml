import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Window {
    visible: true
    id : window_id
    width: 1300
    height: 800
    title: qsTr("scaner")
    color: "beige"

    RowLayout
    {

    anchors.fill : parent

    RowLayout
    {
        Layout.fillWidth: true
        Layout.fillHeight: true
        spacing: 20
        anchors.fill : parent

        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 20
            Layout.bottomMargin: 20

            ColumnLayout
            {

                anchors.fill : parent
                spacing:0

                Rectangle
                {
                   color: window_id.color
                   border.color : "black"
                   Layout.fillWidth: true
                   height : title_in_id.implicitHeight+25

                    Text {
                        id: title_in_id
                        text: qsTr("input ")
                        font.pointSize: 10
                        anchors.centerIn: parent
                    }
                }
                Rectangle
                {

                    id : input_rect_id
                    //border.color : "black"
                    Layout.fillWidth: true
                    Layout.fillHeight: true


                    TextEdit
                    {
                        id : input_id
                        width : parent.width
                        height : parent.height
                        color:"black"
                        wrapMode : TextEdit.Wrap
                        font.pointSize : 10
                        focus: true


                    }


                    }



                }
            }


        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.rightMargin: 20
            Layout.bottomMargin: 20

            ColumnLayout
            {
                anchors.fill : parent
                spacing :0

                Rectangle
                {
                   color: window_id.color
                   border.color : "black"
                   Layout.fillWidth: true
                   height : title_out_id.implicitHeight+25


                    Text {
                        id: title_out_id
                        text: qsTr("output ")
                        font.pointSize: 10
                        anchors.centerIn: parent
                    }
                }
                Rectangle
                {

                    id : output_rect_id
                    Layout.fillWidth: true
                    Layout.fillHeight: true


                    TextEdit
                    {
                        id : output_id
                        width : parent.width
                        height : parent.height
                        color:"black"
                        wrapMode : TextEdit.Wrap
                        font.pointSize : 10



                    }


                    }

                }
            }
    }

   ColumnLayout
   {
       Layout.fillHeight: true
       Layout.fillWidth: true
       Layout.rightMargin: 40
       Layout.alignment: Qt.AlignCenter
       spacing: 20
    Button{
        id : submit_button
        width : submit_button_text.implicitWidth+10
        height : submit_button_text.implicitHeight+10
        Text {
            anchors.centerIn: parent
            id: submit_button_text
            text: qsTr("Submit")
        }
        onClicked:
        {
            output_id.text = core_cpp.core_work(input_id.text)

        }
    }
     Button
     {

         id : clear_button
         width : clear_button_text.implicitWidth
         height: clear_button_text.implicitHeight
             Text {
             anchors.centerIn: parent
             id: clear_button_text
             text: qsTr("Clear all")
         }
         onClicked:
         {

          output_id.clear()
          input_id.clear()
         }

         }

    }

    }
    }







