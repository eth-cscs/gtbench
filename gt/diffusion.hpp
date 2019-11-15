#pragma once

#include "common.hpp"

namespace diffusion {

class horizontal {
  using p_out = gt::arg<0, storage_t>;
  using p_in = gt::arg<1, storage_t>;
  using p_dx = gt::arg<2, global_parameter_t>;
  using p_dy = gt::arg<3, global_parameter_t>;
  using p_dt = gt::arg<4, global_parameter_t>;
  using p_coeff = gt::arg<5, global_parameter_t>;

public:
  horizontal(grid_t const &grid, real_t dx, real_t dy, real_t dt, real_t coeff);

  void operator()(storage_t &out, storage_t const &in);

private:
  gt::computation<p_out, p_in> comp_;
};

class vertical {
  using p_data_in = gt::arg<0, storage_t>;
  using p_data_out = gt::arg<1, storage_t>;
  using p_data_top = gt::arg<2, storage_ij_t>;
  storage_ij_t data_top_;
  using p_data_bottom = gt::arg<3, storage_ij_t>;
  storage_ij_t data_bottom_;

  using p_dz = gt::arg<4, global_parameter_t>;
  using p_dt = gt::arg<5, global_parameter_t>;
  using p_coeff = gt::arg<6, global_parameter_t>;

  using p_a = gt::tmp_arg<7, storage_t>;
  using p_b = gt::tmp_arg<8, storage_t>;
  using p_c = gt::tmp_arg<9, storage_t>;
  using p_d = gt::tmp_arg<10, storage_t>;

  using p_alpha = gt::arg<11, storage_ij_t>;
  storage_ij_t alpha_;
  using p_beta = gt::arg<12, storage_ij_t>;
  storage_ij_t beta_;
  using p_gamma = gt::arg<13, storage_ij_t>;
  storage_ij_t gamma_;
  using p_fact = gt::arg<14, storage_ij_t>;
  storage_ij_t fact_;

  using p_z = gt::tmp_arg<15, storage_t>;
  using p_z_top = gt::arg<16, storage_ij_t>;
  storage_ij_t z_top_;
  using p_x = gt::tmp_arg<17, storage_t>;

public:
  vertical(grid_t const &grid, real_t dz, real_t dt, real_t coeff,
           storage_ij_t::storage_info_t const &sinfo_ij);

  void operator()(storage_t &flux, storage_t const &in);

private:
  gt::computation<p_data_in, p_data_out> comp_;
};

} // namespace diffusion