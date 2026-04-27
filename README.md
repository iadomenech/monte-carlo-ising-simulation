# 🧲 Monte Carlo Simulation of the 2D Ising Model

This repository contains a computational physics project implementing a **Monte Carlo simulation of the two-dimensional Ising model** using the **Metropolis algorithm**.

## Implementation Details

The implementation is intentionally designed with a low-level approach: memory is manually managed using `malloc`, `realloc`, and `free`, and no high-level containers (such as `std::vector`) are used.

### Educational Purpose

This design choice is deliberate. The goal is to provide a deeper understanding of:

- Memory management at a low level  
- Data layout and its impact on performance  
- The internal mechanics of Monte Carlo simulations  

By avoiding high-level abstractions, students are encouraged to engage directly with how data is stored and manipulated in memory.

### Note

As a result, the code may appear less idiomatic compared to modern C++ practices, where RAII and standard containers are preferred. However, this approach prioritizes conceptual clarity and foundational understanding over abstraction.

The goal is to explore the emergence of **phase transitions** and the behavior of the system near the **critical temperature**, where the model exhibits **scale invariance** and universal behavior.

---

## 📌 Overview

The Ising model is a paradigmatic system in statistical physics describing interacting spins  s_i = \pm 1  on a lattice with nearest-neighbor interactions:

$$
H = -J \sum_{\langle i,j \rangle} s_i s_j
$$

Despite its simplicity, the model exhibits a **second-order phase transition** between:

- 🟦 **Ordered phase** (low temperature): spins aligned, non-zero magnetization  
- 🟥 **Disordered phase** (high temperature): random spins, zero magnetization

The critical temperature in 2D is:

$$
T_c \approx 2.27
$$

At this point, the system shows **scale invariance and critical phenomena**.

---

## ⚙️ Numerical Method

The simulation is based on the **Metropolis Monte Carlo algorithm**, which evolves the system according to:

$$
P(s_i \to -s_i) = \exp\left(-\frac{\Delta H}{T}\right)
$$

(with  $J = 1$ and $k_B = 1$).

### Algorithm outline:

1. Initialize a random spin configuration.
2. Select a random spin.
3. Compute energy change $\Delta H$.
4. Accept or reject the flip using the Metropolis criterion.
5. Repeat for $N_P$ iterations until equilibrium.

Periodic boundary conditions are applied in all simulations.

---

## 🧪 Numerical Experiments

### 1. Spin configuration evolution

Simulation of the 2D lattice for different temperatures and equilibration times.

- Output: spin configurations
- Visualization: heatmaps (red/blue spin states)

---

### 2. Thermalization study

Study of magnetization evolution:

$$
m = \frac{1}{N} \sum_i s_i
$$

to verify convergence to equilibrium for different temperatures.

---

### 3. Comparison with Onsager solution

The average magnetization is computed as:

$$
\langle |m| \rangle = \frac{1}{N} \sum_{i=1}^{N} |m_i|
$$

and compared with the exact solution:

$$
|m| = \left(1 - \sinh^{-4}\left(\frac{2}{T}\right)\right)^{1/8}
$$

## 🔹 Simulation execution

The solution is designed to run on Linux systems. Inside the corresponding directory, there is a Makefile provided to compile the code. This Makefile is generic and will work for any program whose name starts with -x-. 