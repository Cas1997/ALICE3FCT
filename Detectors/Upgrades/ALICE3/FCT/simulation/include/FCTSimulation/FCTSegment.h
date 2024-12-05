// Copyright 2019-2020 CERN and copyright holders of ALICE O2.
// See https://alice-o2.web.cern.ch/copyright for details of the copyright holders.
// All rights not expressly granted are reserved.
//
// This software is distributed under the terms of the GNU General Public
// License v3 (GPL Version 3), copied verbatim in the file "COPYING".
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file FCTSegment.h
/// \brief Definition of the FCTSegment class

#ifndef ALICEO2_FCT_SEGMENT_H_
#define ALICEO2_FCT_SEGMENT_H_

#include "Rtypes.h"                 // for Double_t, Int_t, Bool_t, etc
#include "FCTSimulation/Detector.h" // for Detector, Detector::Model

class TGeoVolume;

namespace o2
{
namespace fct
{

/// This class defines the Geometry for the FCT segment TGeo. This is a work class used
/// to study different configurations during the development of the ALICE3 EndCaps
class FCTSegment : public TObject
{
 public:
  // Default constructor
  FCTSegment() = default;

  // Segment constructor
  FCTSegment(Int_t layerNumber, Int_t sectorNumber, Int_t moduleNumber, std::string segmentName, Double_t x, Double_t y, Double_t z, Double_t vertL, Double_t innerL, Double_t outerL, Double_t rotX, Double_t rotY, Double_t rotZ, Float_t segmentx2X0);

  /// Copy constructor
  FCTSegment(const FCTSegment&) = default;

  /// Assignment operator
  FCTSegment& operator=(const FCTSegment&) = default;

  /// Default destructor
  ~FCTSegment() override;

  /// getters
  auto getLayerNumber() const { return mLayerNumber; }
  auto getSectorNumber() const { return mSectorNumber; }
  auto getModuleNumber() const { return mModuleNumber; }
  auto getX() const { return mX; }
  auto getY() const { return mY; }
  auto getZ() const { return mZ; }
  auto getXRot() const { return mX; }
  auto getYRot() const { return mY; }
  auto getZRot() const { return mZ; }
  auto getVertL() const { return mVertL; }
  auto getInnerL() const { return mInnerL; }
  auto getOuterL() const { return mOuterL; }
  auto getx2X0() const { return mx2X0; }

  /// Creates the actual Segment and places inside its mother volume
  /// \param motherVolume the TGeoVolume owing the volume structure
  virtual void createSegment(TGeoVolume* motherVolume);

 private:
  Int_t mLayerNumber = -1;
  Int_t mSectorNumber = -1;
  Int_t mModuleNumber = -1;
  std::string mSegmentName; ///< Current segment name
  Double_t mVertL;          ///< Vertical length of the trapezoid
  Double_t mInnerL;         ///< Inner side length of the trapezoid
  Double_t mOuterL;         ///< Outer side length of the trapezoid
  Double_t mX;              ///< X position of the segment
  Double_t mY;              ///< Y position of the segment
  Double_t mZ;              ///< Z position of the segment
  Double_t mRotX;           ///< X rotation of the segment
  Double_t mRotY;           ///< X rotation of the segment
  Double_t mRotZ;           ///< X rotation of the segment
  Double_t mChipThickness;  ///< Chip thickness
  Double_t mx2X0;           ///< segment material budget x/X0

  ClassDefOverride(FCTSegment, 0); // ALICE 3 EndCaps geometry
};
} // namespace fct
} // namespace o2

#endif
