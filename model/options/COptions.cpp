#include "ui/studiomodel/StudioModel.h"

#include "COptions.h"

COptions Options;

COptions::COptions()
{
	ResetToDefaults();
}

COptions::~COptions()
{
}

void COptions::ResetToDefaults()
{
	showBones = false;

	lightColor[ 0 ] = lightColor[ 1 ] = lightColor[ 2 ] = 1.0;

	trans[ 0 ] = trans[ 1 ] = trans[ 2 ] = 0;
	rot[ 1 ] = rot[ 2 ] = 0;

	rot[ 0 ] = -90.0f;

	transparency = 1.0f;

	showAttachments = false;
	showHitBoxes = false;
	useStencil = false;
	showTexture = false;

	texture = GL_INVALID_TEXTURE_ID;
	textureScale = 1.0f;

	memset( backgroundTextureFile, 0, sizeof( backgroundTextureFile ) );
	memset( groundTextureFile, 0, sizeof( groundTextureFile ) );

	mirror = false;

	renderMode = RenderMode::TEXTURE_SHADED;

	showGround = false;

	groundColor[ 0 ] = 0.85f;
	groundColor[ 1 ] = 0.85f;
	groundColor[ 2 ] = 0.69f;

	pause = false;

	speedScale = 1.0f;

	playSequence = true;

	sequence = 0;

	drawnPolys = 0;

	showEyePosition = false;

	wireframeOverlay = false;

	wireframeColor[ 0 ] = 1.0f;
	wireframeColor[ 1 ] = wireframeColor[ 2 ] = 0;

	weaponOrigin[ 0 ] = weaponOrigin[ 1 ] = weaponOrigin[ 2 ] = 0;

	useWeaponOrigin = false;
}

void COptions::CenterView( const StudioModel& model )
{
	float min[ 3 ], max[ 3 ];
	model.ExtractBbox( min, max );

	float dx = max[ 0 ] - min[ 0 ];
	float dy = max[ 1 ] - min[ 1 ];
	float dz = max[ 2 ] - min[ 2 ];

	float d = dx;

	if( dy > d )
		d = dy;
	if( dz > d )
		d = dz;

	trans[ 0 ] = 0;
	trans[ 1 ] = min[ 2 ] + dz / 2;
	trans[ 2 ] = d * 1.0f;
	rot[ 0 ] = -90.0f;
	rot[ 1 ] = -90.0f;
	rot[ 2 ] = 0.0f;
}

void COptions::SetOrigin( const vec3_t vecOrigin )
{
	VectorCopy( vecOrigin, trans );
}