# cpp-inventario-oop

![stack: C++17](https://img.shields.io/badge/stack--C++17-0d9488?style=flat-square) ![stack: STL](https://img.shields.io/badge/stack--STL-0d9488?style=flat-square) ![stack: make](https://img.shields.io/badge/stack--make-0d9488?style=flat-square)
![IA: asistido](https://img.shields.io/badge/IA--asistido-6366f1?style=flat-square)

Inventario en C++ con clases, STL (vector/map), parseo de CSV y reporte en consola.

> **Transparencia sobre IA:** este proyecto se desarrollo con asistencia de inteligencia artificial (generacion de codigo, revision y documentacion). El codigo fue leido, ejecutado y probado manualmente antes de publicarse. No declara clientes, metricas ni resultados que no puedan verificarse.

## Problema que resuelve

Modelar un inventario de productos evitando el uso de arreglos paralelos y duplicacion de logica de busqueda.

## Solucion implementada

Clases Producto e Inventario con STL (vector/map), busqueda por codigo, calculo de valor total y carga/volcado de un CSV.

### Funcionalidades principales

- Programacion orientada a objetos con encapsulacion
- Busqueda por codigo en O(log n)
- Parseo y volcado de CSV
- Resumen de valor total del inventario

## Stack

- C++17
- STL
- make

## Estructura

```
src/main.cpp      # clase Producto + Inventario
inventario.csv    # datos (sku;nombre;precio;stock)
Makefile
```

## Puesta en marcha

```bash
make run
```

## Complejidad del proyecto

**Nivel: Intermedio** — Varios tipos relacionados, contenedores STL y persistencia en archivo de texto.

El nivel describe la complejidad tecnica del proyecto, no el grado de dominio de quien lo escribio.

## Despliegue

Programa de consola en C++; no tiene interfaz web.  
El codigo fuente si esta disponible en este repositorio.

## Autor

**Luis Felipe Zuniga Leon** — Desarrollador de software asistido por IA

- GitHub: <https://github.com/Luisf2020>

---

_Proyecto de portafolio. El desarrollo se apoyo en herramientas de IA bajo revision tecnica humana._
