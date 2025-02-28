#include "meta/headers.hpp"


/***********************************************************************
     * filterPhysAll

***********************************************************************/
long filterPhysAll =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform |
	1 << ach::PhysType::ptBarrier  |
	1 << ach::PhysType::ptDeath;



/***********************************************************************
     * filterPhysPlayer

***********************************************************************/
long filterPhysPlayer =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform |
	1 << ach::PhysType::ptBarrier  |
	1 << ach::PhysType::ptDeath;



/***********************************************************************
     * filterPhysEnemy

***********************************************************************/
long filterPhysEnemy =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform |
	1 << ach::PhysType::ptBarrier;



/***********************************************************************
     * filterPhysProjectile

***********************************************************************/
long filterPhysProjectile =
	1 << ach::PhysType::ptSolid;



/***********************************************************************
     * filterPhysSolid

***********************************************************************/
long filterPhysSolid =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform;
