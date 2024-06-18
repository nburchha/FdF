# FDF 42 Project

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Introduction

The FDF 42 Project is a graphical tool that visualizes 3D wireframe models from `.fdf` files, which contain coordinate data for 3D models. This project is created using C, and it allows users to view and interact with 3D representations of height maps in a dynamic way.

## Features

- **3D Visualization**: Transforms 2D height map data into interactive 3D wireframe models.
- **Interactivity**: Rotate ('R' + mouse wheel), zoom (mouse wheel), and translate the models for comprehensive viewing ('Q' + mouse wheel, 'W' + mouse wheel). 
- **Colors**: Put RGB colors next to the Coordinate seperated by a comma to see the program creating gradients between the points with colors specified.
- **Different Projections**: There are two types of projections possible, isometric and parallel. You can toggle between these with 'P' on your keyboard.
- **Auto Rotation**: Toggle Auto Rotation with 'I'

## Installation

To install and set up the FDF 42 Project, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/fdf-42-project.git fdf
    cd fdf
    ```

2. **Initialize and update submodules**:
    If your project uses submodules, make sure to initialize and update them:
    ```bash
    git submodule update --init --recursive
    ```

3. **Compile the project**:
    Use `make` to compile the project:
    ```bash
    make
    ```

4. **Run the program**:
    After compilation, you can run the program with a test map:
    ```bash
    ./fdf test_maps/42.fdf
    ```
    In test_maps are many valid test maps to try out the program!

## Usage

To use the FDF 42 Project:

1. **Open an FDF file**:
    Execute the program with the path to a `.fdf` file:
    ```bash
    ./fdf path/to/your_map.fdf
    ```

2. **Navigate the model**:
    - **Rotate**: Press 'R' and use the mouse wheel to rotate the model.
    - **Zoom**: Scroll with the mouse wheel to zoom in and out.
    - **Translation**: Press 'Q' and use the mouse wheel to translate the model vertically, press 'W' and use the mouse wheel for horizontal translation.
    - **Projection**: Press 'P' to change between isometric and parallel projection.

## Examples

Here are some example commands to get you started:

1. **Run with elem-col map**:
    ```bash
    ./fdf maps/elem-col.fdf
    ```

| ![Isometric Projection](https://github.com/nburchha/FdF/assets/67442077/3108d740-11f4-4c00-87aa-a92b941b98e2) | ![Parallel Projection](https://github.com/nburchha/FdF/assets/67442077/277d7fb3-a8aa-4138-bf6b-e2c018a4a140) |
|:--:|:--:|
| *Isometric Projection* | *Parallel Projection* |




3. **Run with t1 map**:
    Try running the program with various `.fdf` files to see different wireframe models:
    ```bash
    ./fdf test_maps/t1.fdf
    ```
    <img width="600" alt="Screenshot 2024-06-18 at 13 20 16" src="https://github.com/nburchha/FdF/assets/67442077/92d29514-4066-412e-98eb-d88a3d896845">
    <img width="600" alt="Screenshot 2024-06-18 at 13 17 52" src="https://github.com/nburchha/FdF/assets/67442077/95b5e463-ad38-421f-9e8d-3c870e99fac3">

    
