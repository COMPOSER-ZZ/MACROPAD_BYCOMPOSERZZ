# MacroPad
## Master Plan

**Documento:** DOC-00

**Versión del documento:** 0.2

**Estado:** 🟨 En desarrollo

---

# Índice

1. Objetivos
2. Filosofía del Proyecto
3. Requisitos
4. Arquitectura General
5. Hardware
6. Firmware
7. Interfaz Web
8. Sistema de Archivos
9. Flujo de Información
10. Roadmap
11. Decisiones de Diseño
12. Riesgos
13. Ideas Futuras
14. Estándares del Proyecto
15. Versionado

---

# 1. Objetivos

Construir un MacroPad profesional basado en ESP32-S3 que funcione como un teclado USB completamente programable, con pantalla gráfica, perfiles dinámicos, almacenamiento interno y configuración mediante navegador web.

El proyecto deberá diseñarse bajo una arquitectura modular, escalable y fácilmente mantenible.

---

# 2. Filosofía del Proyecto

## Objetivos principales

- Modularidad.
- Escalabilidad.
- Código reutilizable.
- Fácil mantenimiento.
- Configuración sin recompilar firmware.
- Firmware independiente del contenido.
- Arquitectura limpia.
- Documentación completa.

## Principios

- Primero se diseña.
- Después se programa.
- Nunca romper una característica ya funcional.
- Cada módulo tendrá una única responsabilidad.
- Todo cambio importante deberá documentarse.
- Todo módulo deberá poder probarse de forma independiente.

---

# 3. Requisitos

## Funcionales

- [ ] Funcionar como teclado USB HID.
- [ ] Detectar pulsación corta.
- [ ] Detectar pulsación larga.
- [ ] Detectar doble clic.
- [ ] Soportar múltiples perfiles.
- [ ] Cambiar perfiles manualmente.
- [ ] Permitir perfiles automáticos.
- [ ] Mostrar información en pantalla.
- [ ] Reproducir animaciones.
- [ ] Configuración mediante navegador web.
- [ ] Almacenar configuraciones en memoria Flash.
- [ ] Actualizar recursos sin recompilar firmware.

## No funcionales

- [ ] Funcionar sin instalar software.
- [ ] Bajo consumo.
- [ ] Firmware modular.
- [ ] Fácil actualización.
- [ ] Fácil mantenimiento.
- [ ] Código documentado.

---

# 4. Arquitectura General

```mermaid
flowchart LR

Usuario --> Botones

Botones --> ButtonManager

ButtonManager --> ProfileManager

ProfileManager --> ActionManager

ActionManager --> USBHID

USBHID --> Computadora
```

---

# 5. Hardware

Pendiente.

---

# 6. Firmware

Pendiente.

---

# 7. Interfaz Web

Pendiente.

---

# 8. Sistema de Archivos

Pendiente.

---

# 9. Flujo de Información

Pendiente.

---

# 10. Roadmap

Pendiente.

---

# 11. Decisiones de Diseño

Pendiente.

---

# 12. Riesgos

Pendiente.

---

# 13. Ideas Futuras

Pendiente.

---

# 14. Estándares del Proyecto

Toda la documentación referente a:

- Organización del proyecto.
- Nomenclatura.
- Convenciones de programación.
- Reglas de arquitectura.
- Convenciones de documentación.
- Estándares de desarrollo.

se encontrará en el documento:

**DOC-14 - ProjectStandards.md**

---

# 15. Versionado

| Versión | Descripción |
|----------|-------------|
| 0.1 | Inicio del proyecto |
| 0.2 | Definición de la arquitectura principal y estructura documental |