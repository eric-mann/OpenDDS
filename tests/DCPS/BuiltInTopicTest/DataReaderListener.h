// -*- C++ -*-
//
#ifndef DATAREADER_LISTENER_IMPL
#define DATAREADER_LISTENER_IMPL

#include <dds/DdsDcpsSubscriptionExtC.h>
#include <dds/DCPS/LocalObject.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


//Class DataReaderListenerImpl
class DataReaderListenerImpl
  : public virtual OpenDDS::DCPS::LocalObject<DDS::DataReaderListener>
{
public:
  //Constructor
  DataReaderListenerImpl ();

  //Destructor
  virtual ~DataReaderListenerImpl (void);

  virtual void on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus & status)
    throw (CORBA::SystemException);

  virtual void on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus & status)
  throw (CORBA::SystemException);

  virtual void on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus & status)
  throw (CORBA::SystemException);

  virtual void on_subscription_matched (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchedStatus & status
  )
  throw (CORBA::SystemException);

  virtual void on_sample_rejected(
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& status
  )
  throw (CORBA::SystemException);

  virtual void on_data_available(
    DDS::DataReader_ptr reader
  )
  throw (CORBA::SystemException);

  virtual void on_sample_lost(
    DDS::DataReader_ptr reader,
    const DDS::SampleLostStatus& status
  )
  throw (CORBA::SystemException);

  virtual void on_subscription_disconnected (
    DDS::DataReader_ptr reader,
    const ::OpenDDS::DCPS::SubscriptionDisconnectedStatus & status
  )
  throw (CORBA::SystemException);

  virtual void on_subscription_reconnected (
    DDS::DataReader_ptr reader,
    const ::OpenDDS::DCPS::SubscriptionReconnectedStatus & status
  )
  throw (CORBA::SystemException);

  virtual void on_subscription_lost (
    DDS::DataReader_ptr reader,
    const ::OpenDDS::DCPS::SubscriptionLostStatus & status
  )
  throw (CORBA::SystemException);

  virtual void on_connection_deleted (
  DDS::DataReader_ptr)
  throw (CORBA::SystemException);

  long num_reads() const {
    return num_reads_;
  }

  void set_builtin_datareader (DDS::DataReader_ptr builtin);

  bool builtin_read_errors () const {
    return builtin_read_error_;
  }

private:

  DDS::DataReader_var     reader_;
  long                    num_reads_;
  ::DDS::InstanceHandle_t publication_handle_;
  ::DDS::InstanceHandle_t post_restart_publication_handle_;
  bool                    builtin_read_error_;
  DDS::DataReader_var     builtin_;
};

#endif /* DATAREADER_LISTENER_IMPL  */
