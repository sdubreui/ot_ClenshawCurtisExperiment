//                                               -*- C++ -*-
/**
 *  @brief ClenshawCurtisExperimentClass
 *
 *  Copyright 2005-2019 Airbus-EDF-IMACS-ONERA-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "clenshawcurtisexperiment/ClenshawCurtisExperimentClass.hxx"
#include <openturns/OT.hxx>
using namespace OT;

namespace CLENSHAWCURTISEXPERIMENT
{

CLASSNAMEINIT(ClenshawCurtisExperimentClass);


/* Default constructor */
ClenshawCurtisExperimentClass::ClenshawCurtisExperimentClass()
  : WeightedExperimentImplementation(),
  marginalDegrees_(0),
  nodes_(0,0),
  weights(0)
{
  // Nothing to do
}

ClenshawCurtisExperimentClass::ClenshawCurtisExperimentClass(const Indices & marginalDegrees):
  WeightedExperimentImplementation(),
  marginalDegrees_(0),
  nodes_(0,0),
  weights(0)
{
 // Set the default distribution
 setDistributionAndMarginalDegrees(ComposedDistribution(ComposedDistribution::DistributionCollection(marginalDegrees.getSize())), marginalDegrees); 
}

/* Constructor with parameters */
ClenshawCurtisExperimentClass::ClenshawCurtisExperimentClass(const Distribution & distribution, const Indices & marginalDegrees):
  WeightedExperimentImplementation(),
  collection_(0),
  marginalDegrees_(0),
  nodes_(0, 0)
{
  setDistributionAndMarginalDegrees(distribution, marginalDegrees);
}

/* Virtual constructor */
ClenshawCurtisExperimentClass * ClenshawCurtisExperimentClass::clone() const
{
  return new ClenshawCurtisExperimentClass(*this);
}

/* String converter */
String ClenshawCurtisExperimentClass::__repr__() const
{
  OSS oss;
  oss << "class=" << GetClassName()
      << " name=" << getName()
      << " distribution=" << distribution_
      << " size=" << size_
  return oss;
}

String ClenshawCurtisExperimentClass::__str__(const String & ) const
{
  OSS oss;
  oss << GetClassName()
      << ", distribution=" << distribution_
      << ", size" << size_
  return oss;
}

/* Method save() stores the object through the StorageManager */
void ClenshawCurtisExperimentClass::save(Advocate & adv) const
{
  WeightedExperimentImplementation::save(adv);
}

/* Method load() reloads the object from the StorageManager */
void ClenshawCurtisExperimentClass::load(Advocate & adv)
{
  WeightedExperimentImplementation::load(adv);
  setDistribution(distribution_);
}

/* Distribution accessor */
void ClenshawCurtisExperimentClass::setDistribution(const Distribution & distribution)
{
  const UnsignedInteger dimension = distribution.getDimension();
  // Build the iso-probabilistic transformation
  // For distributions with non-indepedent copula, it resorts to using the method
  // described in:
  // Mathieu Cambou, Marius Hofert, Christiane Lemieux, "Quasi-Random numbers for copula models", Statistics and Computing, September 2017, Volume 27, Issue 5, pp 1307–1329
  // preprint here: https://arxiv.org/pdf/1508.03483.pdf
  transformation_ = DistributionTransformation(ComposedDistribution(Collection<Distribution>(dimension, Uniform(-1.0, 1.0))), distribution);
  WeightedExperimentImplementation::setDistribution(distribution);
}


/** Marginal degrees accessor */
void GaussProductExperiment::setDistributionAndMarginalDegrees(const Distribution & distribution,
    const Indices & marginalDegrees)
{
  // Set the marginal degrees here then the distribution with checks
  marginalDegrees_ = marginalDegrees;
  setDistribution(distribution);

  const UnsignedInteger dimension = distribution_.getDimension();
  size_ = 1;
  for (UnsignedInteger i = 0; i < dimension; ++ i)
  {
    const UnsignedInteger dI = marginalDegrees_[i];
    size_ *= dI;
  }
}

Indices GaussProductExperiment::getMarginalDegrees() const
{
  return marginalDegrees_;
}

/* Sample generation */
Sample ClenshawCurtisExperimentClass::generateWithWeights(Point & weights) const
{

  const UnsignedInteger dimension = distribution_.getDimension();
  algo = ClenshawCurtis(marginalDegrees_);
  sample = algo.getNodes()
  weights = algo.getWeights()
  sample = transformation_(sample);
  return sample;
}

END_NAMESPACE_OPENTURNS
