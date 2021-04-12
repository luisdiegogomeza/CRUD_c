// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include<mysql.h>
#include <iostream>
using namespace std;

int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_empresa", "empres@123", 3306, NULL, 0);
    void insert_productos()
    {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
        if (conectar)
        {
            string producto, descripcion, fecha_ingreso = "now()";
            string id_marca, existencia, precio_costo, precio_venta;
            //int id_marca, existencia;
            //double precio_costo, precio_venta;

            cout << "\ningrese el producto: ";
            getline(cin, producto);
            cout << "\ningrese el id_marca: ";
            cin >> id_marca;
            cin.ignore();
            cout << "\ningrese la descripcion: ";
            getline(cin, descripcion);
            cout << "\ningrese el precio costo: ";
            cin >> precio_costo;
            cin.ignore();
            cout << "\ningrese el precio venta: ";
            cin >> precio_venta;
            cin.ignore();
            cout << "\ningrese las existencias: ";
            cin >> existencia;
            cout << "\nla fecha de ingreso será esta hora en la que se estan ingresando datos" << endl;

            string insert = "insert into productos(producto,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + producto + "' , " + id_marca + " , '" + descripcion + "' , " + precio_costo + "," + precio_venta + "," + existencia + "," + fecha_ingreso + ")";
            const char* i = insert.c_str();
            q_estado = mysql_query(conectar, i);
            if (!q_estado)
            {
                cout << "insert exitoso" << endl;
            }
            else
            {
                cout << "error en insert" << endl;
            }
        }
    }
    void update_marcas()
    {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
        if (conectar)
        {
            string marca, id;
            cout << "ingrese el id del registro que desea modificar: ";
            cin >> id;
            cin.ignore();
            cout << "ingrese la nueva marca: ";
            getline(cin, marca);
            string update = "update marcas set marca= '" + marca + "' where id_marca= " + id;
            const char* i = update.c_str();
            q_estado = mysql_query(conectar, i);
            if (!q_estado)
            {
                cout << "update exitoso" << endl;
            }
            else
            {
                cout << "error en el update" << endl;
            }
        }
    }

    void update_productos()
    {
        MYSQL* conectar;

        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
        cout << endl << endl;
        if (conectar)
        {
            string producto, id_marca, descripcion, precio_costo, precio_venta, existencias, id_producto, update_id_prod, update;
            int opcion;
            cout << "Ingrese el id del registro que desea modificar: ";
            cin >> id_producto;
            cin.ignore();
            Sleep(500);
            system("cls");
            cout << "   1. Producto" << endl;
            cout << "   2. Descripcion" << endl;
            cout << "   3. Precio_costo" << endl;
            cout << "   4. Precio_venta" << endl;
            cout << "   5. Existencias" << endl;
            cout << "Que elemento desea modificar: ";
            cin >> opcion;
            cin.ignore();
            switch (opcion)
            {
            case 1:
                cout << "modifique el producto: ";
                getline(cin, producto);
                update = "update productos set producto= '" + producto + "' where id_producto= " + id_producto;
                break;
            case 2:
                cout << "modifique la descripcion: ";
                getline(cin, descripcion);
                update = "update productos set descripcion= '" + descripcion + "' where id_producto= " + id_producto;
                break;
            case 3:
                cout << "modifique el precio_costo: ";
                cin >> precio_costo;
                update = "update productos set precio_costo= " + precio_costo + " where id_producto= " + id_producto;
                break;
            case 4:
                cout << "ingrese la modificacion de precio_venta: ";
                cin >> precio_venta;
                update = "update productos set precio_venta= " + precio_venta + " where id_producto= " + id_producto;
                break;
            case 5:
                cout << "ingrese la modificacion de existencias: ";
                cin >> existencias;
                update = "update productos set existencia= " + existencias + " where id_producto= " + id_producto;
                break;
            default:
                cout << "esa opcion no existe" << endl;
                break;
            }

            const char* q = update.c_str();
            q_estado = mysql_query(conectar, q);
            if (!q_estado)
            {
                cout << "update exitoso" << endl;
            }
            else
            {
                cout << "error en update" << endl;
            }
        }
    }
    void delete_marcas()
    {
        MYSQL* conectar;
        conectar = mysql_init(0);
        conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
        if (conectar)
        {
            string marca, id;
            cout << "ingrese el id del registro que desea eliminar: ";
            cin >> id;
            cin.ignore();
            string update = "delete from marcas where id_marca= " + id;
            const char* i = update.c_str();
            q_estado = mysql_query(conectar, i);
            if (!q_estado)
            {
                cout << "delete exitoso" << endl;
            }
            else
            {
                cout << "error en el delete" << endl;
            }
        }
    }

    system("pause");
    return 0;
}
