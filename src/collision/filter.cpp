#include "meta/headers.hpp"


/***********************************************************************
     * filterPhysAll

***********************************************************************/
long filterPhysAll =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform |
	1 << ach::PhysType::ptBarrier  |
	1 << ach::PhysType::ptDeath    |
	1 << ach::PhysType::ptBounce;



/***********************************************************************
     * filterPhysPlayer

***********************************************************************/
long filterPhysPlayer =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform |
	1 << ach::PhysType::ptBarrier  |
	1 << ach::PhysType::ptDeath    |
	1 << ach::PhysType::ptBounce;



/***********************************************************************
     * filterPhysEnemy

***********************************************************************/
long filterPhysEnemy =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform |
	1 << ach::PhysType::ptBarrier  |
	1 << ach::PhysType::ptBounce;



/***********************************************************************
     * filterPhysProjectile

***********************************************************************/
long filterPhysProjectile =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptBounce;



/***********************************************************************
     * filterPhysSolid

***********************************************************************/
long filterPhysSolid =
	1 << ach::PhysType::ptSolid    |
	1 << ach::PhysType::ptPlatform;
