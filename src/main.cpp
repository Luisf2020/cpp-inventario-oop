// Inventario con POO: clase, contenedores STL, archivo y reporte ordenado.
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

class Producto {
public:
    Producto(std::string sku, std::string nombre, double precio, int stock)
        : sku_(std::move(sku)), nombre_(std::move(nombre)), precio_(precio), stock_(stock) {}

    const std::string& sku() const { return sku_; }
    const std::string& nombre() const { return nombre_; }
    double precio() const { return precio_; }
    int stock() const { return stock_; }
    double valor() const { return precio_ * stock_; }

private:
    std::string sku_;
    std::string nombre_;
    double precio_;
    int stock_;
};

class Inventario {
public:
    bool cargar(const std::string& ruta) {
        std::ifstream in(ruta);
        if (!in) return false;
        std::string linea;
        while (std::getline(in, linea)) {
            if (linea.empty()) continue;
            std::stringstream ss(linea);
            std::string sku, nombre, precio, stock;
            std::getline(ss, sku, ';');
            std::getline(ss, nombre, ';');
            std::getline(ss, precio, ';');
            std::getline(ss, stock, ';');
            try {
                productos_.emplace_back(sku, nombre, std::stod(precio), std::stoi(stock));
            } catch (const std::exception&) {
                std::cerr << "linea invalida: " << linea << '\n';
            }
        }
        return true;
    }

    double total() const {
        double t = 0.0;
        for (const auto& p : productos_) t += p.valor();
        return t;
    }

    std::map<std::string, double> porProducto() const {
        std::map<std::string, double> m;
        for (const auto& p : productos_) m[p.nombre()] = p.valor();
        return m;
    }

    const std::vector<Producto>& productos() const { return productos_; }

private:
    std::vector<Producto> productos_;
};

int main(int argc, char** argv) {
    const std::string ruta = (argc > 1) ? argv[1] : "inventario.csv";
    Inventario inv;
    if (!inv.cargar(ruta)) { std::cerr << "no se pudo abrir " << ruta << '\n'; return 1; }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "SKU    PRODUCTO                 PRECIO    STOCK   VALOR\n";
    for (const auto& p : inv.productos()) {
        std::cout << std::left << std::setw(7) << p.sku()
                  << std::setw(24) << p.nombre()
                  << std::right << std::setw(8) << p.precio()
                  << std::setw(8) << p.stock()
                  << std::setw(9) << p.valor() << '\n';
    }
    std::cout << "Valor total del inventario: " << inv.total() << '\n';
    return 0;
}
