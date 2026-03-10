#include <pybind11/pybind11.h>

#include <fsk4/apco25_f.h>
#include <fsk4/demod_ff.h>
#include <fsk4/generic_f.h>
#include <fsk4/rdlap_f.h>
#include <gnuradio/basic_block.h>
#include <gnuradio/block.h>

namespace py = pybind11;

using demod_ff = gr::fsk4::demod_ff;
using generic_f = gr::fsk4::generic_f;
using apco25_f = gr::fsk4::apco25_f;
using rdlap_f = gr::fsk4::rdlap_f;

PYBIND11_MODULE(fsk4_python, m)
{
    py::module::import("gnuradio.gr");

    py::class_<demod_ff, gr::block, gr::basic_block, std::shared_ptr<demod_ff>>(m, "demod_ff")
        .def(py::init(&demod_ff::make),
             py::arg("queue"),
             py::arg("sample_rate"),
             py::arg("symbol_rate"));

    py::class_<generic_f, gr::block, gr::basic_block, std::shared_ptr<generic_f>>(m, "generic_f")
        .def(py::init(&generic_f::make), py::arg("queue"), py::arg("processing_flags"));

    py::class_<apco25_f, gr::block, gr::basic_block, std::shared_ptr<apco25_f>>(m, "apco25_f")
        .def(py::init(&apco25_f::make), py::arg("queue"), py::arg("processing_flags"));

    py::class_<rdlap_f, gr::block, gr::basic_block, std::shared_ptr<rdlap_f>>(m, "rdlap_f")
        .def(py::init(&rdlap_f::make), py::arg("queue"), py::arg("processing_flags"));
}
