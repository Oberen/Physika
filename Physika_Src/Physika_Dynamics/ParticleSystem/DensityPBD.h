#ifndef FRAMEWORK_DENSITYPBD_H
#define FRAMEWORK_DENSITYPBD_H

#include "Platform.h"
#include "Physika_Core/DataTypes.h"
#include "Framework/Module.h"
#include "Physika_Core/Cuda_Array/Array.h"
#include "DensityConstraint.h"
#include "Kernel.h"
#include "SummationDensity.h"
#include "Attribute.h"

namespace Physika {

	template<typename TDataType>
	class DensityPBD : public DensityConstraint<TDataType>
	{
		DECLARE_CLASS_1(DensityPBD, TDataType)
	public:
		typedef typename TDataType::Real Real;
		typedef typename TDataType::Coord Coord;

		DensityPBD();
		~DensityPBD() override {};

		bool execute() override;

// 		static DensityPBD* Create(ParticleSystem<TDataType>* parent, DeviceType deviceType = DeviceType::GPU)
// 		{
// 			return new DensityPBD(parent, deviceType);
// 		}
		bool connectAttribute(std::shared_ptr<Field>& att) { return connect(att, m_attribute); }
		bool connectMass(std::shared_ptr<Field>& mass) { return connect(mass, m_mass); }

	protected:
		int m_maxIteration;
		DeviceBuffer<Real>* m_lamda;
		DeviceBuffer<Coord>* m_deltaPos;
		
		Slot<HostVariable<Real>>  m_mass;
		Slot<DeviceBuffer<Attribute>> m_attribute;

		SummationDensity<TDataType>* densitySum;
	};


#ifdef PRECISION_FLOAT
	template class DensityPBD<DataType3f>;
#else
 	template class DensityPBD<DataType3d>;
#endif
}

#endif