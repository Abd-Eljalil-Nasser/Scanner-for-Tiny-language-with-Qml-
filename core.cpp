#include "core.h"

core::core(QObject *parent) : QObject(parent)
{

}

QString core::core_work(QString input)
{
    QStack<int> x;
    QString reservedWords[8] = {"if","then","else","end","repeat","until","read","write"};
    QString specialSymbols[10] = {"+","-","*","/","=","<","(",")",";",":="};
    QString symbolName[10] = {"Plus","Minus","Multiply","Division","Equal","Smaller than","Open Bracket","Close Bracket","Semicolon","Assign"};
    QString id = "";
    QString num = "";
    int lineCount = 1;
    QString outputtext ="";
    for(int i =0 ; i < input.length() ; i++)
    {
        if (input[i]=="{")
        {
            int old_line_count = lineCount;
            int f=0;
            i++;
            x.push(i);
            while (i <input.length())
            {
                if (input[i] !='}' && input[i] !='{')
                {
                    if (input[i] == '\n')
                    {
                        lineCount++;
                    }
                    i++;
                }
                else if (input[i] =='{')
                {
                    x.push(i);
                    i++;
                }
                else
                {
                    x.pop();
                    if (x.empty()==true)
                    {

                        f=1;
                        break;
                    }
                    i++;
                }
            }
            if (i==input.length() && x.empty()==false)
            {
                outputtext = outputtext+"XX Error on line "+QString::number(old_line_count)+ " comment isn't closed";
                return outputtext;
            }
            if (f==1)
                continue;
        }
        if (i ==input.length())
        {
            break;
        }
        if(i < input.length()&& input[i] == '\n')
        {
            lineCount++;
            continue;
        }

        int flag=0;
        if ( (input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
        {
            id = "";
            while (i < input.length())
            {
                if (( input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
                {
                    id = id+input[i];
                    i++;
                }
                else
                {
                    if (input[i].isDigit())
                    {
                        outputtext = outputtext+ "XX Error on line "+QString::number(lineCount);
                        return outputtext;

                    }
                    break;
                }
            }
            for (int r = 0; r < 8 ; r++)
            {
                if (id == reservedWords[r])
                {
                    QString tempid = id;
                    for(int d = 0 ; d < tempid.length() ; d++)
                    {
                        tempid[d]=static_cast<QChar>(tempid.at(d).unicode()-32);
                    }
                    //cout << id << " , " << tempid << endl;
                    outputtext = outputtext+ id+" , " +tempid+" "+"\n";
                    id = "";
                    flag=1;
                    break;
                }
            }

            if (id != "")
            {
                // cout << id <<" , " << "Identifier" << endl;
                outputtext = outputtext+id+" , " + "Identifier"+" "+"\n";
                id = "";
                i--;
                continue;
            }
            else if(flag==1)
            {
                i--;
                continue;
            }
        }

        while (i < input.length())
        {
            if(input[i].isDigit())
            {
                num += input[i];
                i++;
                flag=1;
            }
            else
            {
                if ((input[i] > 64 && input[i] < 91) || (input[i] > 96 && input[i] < 123))
                {
                    outputtext = outputtext+"XX Error on line "+QString::number(lineCount);
                    return outputtext;

                }
                break;
            }
        }
        if (flag==1)
        {
            //cout << num <<" , " << "Number" << endl;
            outputtext = outputtext+num+" , " + "Number"+" "+"\n";
            num = "";
            i--;
            continue;
        }
        if (input[i]==":" && i<input.length()-1)
        {
            if (input[i+1]=="=")
            {
                outputtext = outputtext+":=" +" , " + "Assign"+" "+"\n";
                i++;
                continue;
            }
            else
            {
                outputtext = outputtext+"XX Error on line "+QString::number(lineCount);
                return outputtext;

            }
        }
        else
        {
            for (int r = 0; r < 9 ; r++)
            {
                if (input[i]==specialSymbols[r])
                {
                    outputtext = outputtext+specialSymbols[r]+" , " +symbolName[r]+" "+"\n";
                    flag=1;
                    break;
                }
            }
            if (flag==1)
            {
                continue;
            }
            else
            {
                if (input[i]==" ")
                {
                    continue;
                }
                outputtext = outputtext+"XX Error on line "+QString::number(lineCount);
                return outputtext;

            }
        }
    }
    return outputtext;
}



