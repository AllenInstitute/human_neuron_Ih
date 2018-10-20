.. Brain Modeling Toolkit documentation master file, created by
   sphinx-quickstart on Tue Sep 26 10:33:33 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.


Welcome to the Brain Modeling Toolkit
=====================================

.. toctree::
   :maxdepth: 2
   :titlesonly:
   :hidden:

   builder
   simulators
   Source Documentation <bmtk>


The Brain Modeling Toolkit (BMTK) is a software package for creating and simulating large-scale brain models. It
supports building, simulation and analysis of models of different levels of resolution including
  * Biophysically detailed networks.
  * Point neuron networks.
  * Population-level networks.
  * Machine-learning networks.


Base Installation
=================
BMTK currently runs on Python 2.7. In additon it requires the following packages to begin building networks:
  * `numpy <http://www.numpy.org/>`_
  * `h5py <http://www.h5py.org/>`_
  * `pandas <http://pandas.pydata.org/>`_
  * `jsonschema <https://pypi.python.org/pypi/jsonschema>`_

To checkout the latest version of the bmtk and install the base requirements please run the following from a
command-line
 ::

    git clone https://github.com/AllenInstitute/bmtk.git
    python setup.py install

In additon, running simulations will have additional requirements depending on the simulation-engine (i.e. level of
resolution) involved. Please refere to the individual simulation engines documentation.


