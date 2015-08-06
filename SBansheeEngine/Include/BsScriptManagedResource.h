#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptResource.h"
#include "BsScriptObject.h"

namespace BansheeEngine
{
	/**
	 * @brief	Interop class between C++ & CLR for ManagedResource.
	 */
	class BS_SCR_BE_EXPORT ScriptManagedResource : public ScriptObject<ScriptManagedResource, ScriptResourceBase>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, "BansheeEngine", "ManagedResource")

		ScriptManagedResource(MonoObject* instance, const HManagedResource& resource);

		/**
		 * @copydoc	ScriptResourceBase::getNativeHandle
		 */
		HResource getNativeHandle() const override { return mResource; }

		/**
		 * @copydoc	ScriptResourceBase::setNativeHandle
		 */
		void setNativeHandle(const HResource& resource) override;
	private:
		friend class ScriptResourceManager;

		/**
		 * @copydoc	ScriptObjectBase::beginRefresh
		 */
		virtual ScriptObjectBackup beginRefresh() override;

		/**
		 * @copydoc	ScriptObjectBase::endRefresh
		 */
		virtual void endRefresh(const ScriptObjectBackup& backupData) override;

		/**
		 * @copydoc	ScriptObjectBase::_createManagedInstance
		 */
		virtual MonoObject* _createManagedInstance(bool construct) override;

		/**
		 * @copydoc	ScriptObjectBase::_onManagedInstanceDeleted
		 */
		void _onManagedInstanceDeleted() override;

		HManagedResource mResource;
		String mNamespace;
		String mType;

		/************************************************************************/
		/* 								CLR HOOKS						   		*/
		/************************************************************************/
		static void internal_createInstance(MonoObject* instance);
	};
}